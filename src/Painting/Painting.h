//
// Created by user on 16.10.2025.
//

#ifndef LABWORK2_PAINTING_H
#define LABWORK2_PAINTING_H
#include "../Exhibit/Exhibit.h"
#include <string>

class Painting : public Exhibit {
    public:
    Painting() = default;

    std::string GetArtist() const;
    std::string GetStyle() const;
    std::string GetMaterial() const;

    int GetLength() const;
    int GetWidth() const;

    void SetArtist(std::string artist);
    void SetStyle(std::string style);
    void SetMaterial(std::string material);

    void SetLength(int length);
    void SetWidth(int width);

    std::string GetExhibitType() const override;

    private:
    std::string artist_;
    std::string style_;
    std::string material_;

    int length_ = 0;
    int width_ = 0;
};

#endif //LABWORK2_PAINTING_H