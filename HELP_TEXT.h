//
// Created by orys on 16.04.23.
//

#ifndef MANOTOM_GENERATEBLANKS_HELP_TEXT_H
#define MANOTOM_GENERATEBLANKS_HELP_TEXT_H

const char* HELP_TEXT = R"(
Использование: имя_программы <команда> [<аргументы>]

Команды:
  -c <входной_файл> <выходной_файл>
    Конвертировать кодировку входного файла в UTF-8 и сохранить в выходном файле.

  -C <входной_файл> <выходной_файл> <исходная_кодировка> <целевая_кодировка>
    Конвертировать кодировку входного файла из исходной_кодировки в целевую_кодировку и сохранить в выходном файле.

  -new [<путь>]
    Создать новый путь.

  -edit <аргумент_пути> <значение>...
    Редактировать указанный путь.

  -печать <арг1> <арг2> <арг3> <арг4> <арг5> <арг6> <арг7> <арг8>
  -print <арг1> <арг2> <арг3> <арг4> <арг5> <арг6> <арг7> <арг8>
    Выполнить печать с указанными настройками.

  -help
    Отобразить данное справочное сообщение.
)";

#endif //MANOTOM_GENERATEBLANKS_HELP_TEXT_H