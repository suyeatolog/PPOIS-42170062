#ifndef LABWORK2_HANDMADETOWEL_H
#define LABWORK2_HANDMADETOWEL_H
#include "../Exhibit/Exhibit.h"
#include <string>

class HandmadeTowel : public Exhibit {
public:
    HandmadeTowel() = default;

    std::string GetFabricType() const;
    std::string GetEmbroideryStyle() const;
    std::string GetColorScheme() const;
    int GetLength() const;
    int GetWidth() const;
    bool GetIsDecorative() const;

    void SetFabricType(std::string fabric);
    void SetEmbroideryStyle(std::string style);
    void SetColorScheme(std::string colors);
    void SetLength(int length);
    void SetWidth(int width);
    void SetIsDecorative(bool decorative);

    std::string GetExhibitType() const override;

private:
    std::string fabricType_;
    std::string embroideryStyle_;
    std::string colorScheme_;
    int length_ = 0;
    int width_ = 0;
    bool isDecorative_ = true;
};

#endif //LABWORK2_HANDMADETOWEL_H