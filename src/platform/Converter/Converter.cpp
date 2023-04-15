#include "Converter.h"

namespace fs = std::filesystem;

void Converter::ConvertUTF(const std::string& path_in, const std::string& path_out,
                           const std::string& from_charset, const std::string& to_charset) {
    if (path_in == path_out) {
        std::cerr << "Input and output paths cannot be the same" << std::endl;
        return;
    }

    copyDirectories(path_in, path_out);

    fs::path start_path(path_in);
    for (const auto& entry : fs::recursive_directory_iterator(path_in)) {
        if (fs::is_regular_file(entry.path())) {
            auto ext = entry.path().extension();
            auto relative_path = entry.path().lexically_relative(start_path);

            if (ext == ".cfm" || ext == ".tbl" || ext == ".згт") {
                convertFile(from_charset, to_charset,
                            path_in / relative_path,
                            path_out / relative_path);
            } else {
                fs::copy(path_in / relative_path, path_out / relative_path);
            }
        }
    }
}

void Converter::copyDirectories(fs::path source, fs::path target) {
    fs::create_directories(target);
    for (const auto& entry : fs::directory_iterator(source)) {
        if (fs::is_directory(entry)) {
            copyDirectories(entry, target / entry.path().filename());
        }
    }
}

bool Converter::convertFile(const std::string& from_charset, const std::string& to_charset,
                            const std::string& input_file, const std::string& output_file) {
    iconv_t cd = iconv_open(to_charset.c_str(), from_charset.c_str());
    if (cd == (iconv_t)-1) {
        std::cerr << "iconv_open error: " << strerror(errno) << std::endl;
        return false;
    }

    std::ifstream ifs(input_file);
    if (!ifs.is_open()) {
        std::cerr << "Failed to open input file: " << strerror(errno) << std::endl;
        return false;
    }

    std::ofstream ofs(output_file);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open output file: " << strerror(errno) << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        char *inbuf = const_cast<char *>(line.c_str());
        size_t inbytesleft = line.length();
        size_t outbytesleft = inbytesleft * 4;
        char *outbuf = new char[outbytesleft];

        char *inptr = inbuf;
        char *outptr = outbuf;

        if (iconv(cd, &inptr, &inbytesleft, &outptr, &outbytesleft) == (size_t)-1) {
            std::cerr << "iconv error: " << strerror(errno) << std::endl;
            std::cerr << input_file << std::endl;
            delete[] outbuf;
            return false;
        }
        *outptr = '\0';

        ofs << outbuf << std::endl;

        delete[] outbuf;
    }

    iconv_close(cd);

    return true;
}