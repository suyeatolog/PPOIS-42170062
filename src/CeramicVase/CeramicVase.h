#ifndef LABWORK2_CERAMICVASE_H
#define LABWORK2_CERAMICVASE_H
#include "../Exhibit/Exhibit.h"
#include <string>

class CeramicVase : public Exhibit {
public:
    CeramicVase() = default;

    std::string GetPattern() const;
    bool GetFragile() const;
    int GetLength() const;
    int GetWidth() const;
    int GetHeight() const;

    void SetPattern(std::string pattern);
    void SetFragile(bool fragile);
    void SetLength(int length);
    void SetWidth(int width);
    void SetHeight(int height);

    std::string GetExhibitType() const;
private:
    std::string pattern_;
    bool isFragile_ = true;
    int length_ = 0;
    int width_ = 0;
    int height_ = 0;
};

#endif //LABWORK2_CERAMICVASE_H