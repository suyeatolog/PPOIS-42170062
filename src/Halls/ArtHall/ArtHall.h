#ifndef LABWORK2_ARTHALL_H
#define LABWORK2_ARTHALL_H
#include "../Hall.h"
#include <string>

class ArtHall : public Hall {
public:
    ArtHall() = default;
    ~ArtHall() = default;

    std::string GetArtPeriod() const;

    void SetArtPeriod(std::string period);

    std::string GetHallType() const override;

private:
    std::string artPeriod_;
};

#endif //LABWORK2_ARTHALL_H