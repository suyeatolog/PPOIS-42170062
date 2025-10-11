//
// Created by Komp on 28.09.2025.
//
/*! \file ReadFile.h
*  \brief Заголовочный файл с описанием класса ReadFile
*  \details Содержит объявление класса ReadFile,
*           который предоставляет статические методы для чтения
*           словаря из текстового файла и проверки существования файлов.
*/
#ifndef LABWORK1_READFILE_H
#define LABWORK1_READFILE_H

#include <string>
#include <vector>

/*! \class ReadFile
 *  \brief Класс для работы с файлами словаря
 *  \details Предоставляет статические методы для чтения словаря из файла
 *           и проверки существования файлов. Все методы класса являются
 *           статическими и не требуют создания экземпляра класса.
 */
class ReadFile {
    public:

    /*! \brief Чтение словаря из файла
     *  \param filename Путь к файлу словаря для чтения
     *  \return Вектор пар "английское слово - русский перевод"
     *  \details Читает файл построчно, каждая строка должна быть в формате:
     *           "english_word=russian_translation".
     *  \warning Выводит сообщения об ошибках в консоль при проблемах с файлом
     */
    static std::vector<std::pair<std::string, std::string>> ReadDictionary(const std::string& filename);

    /*! \brief Проверка существования файла
     *  \param filename Путь к файлу для проверки
     *  \return true если файл существует и доступен для чтения, false в противном случае
     */
    static bool FileExists(const std::string& filename);
};

#endif //LABWORK1_READFILE_H