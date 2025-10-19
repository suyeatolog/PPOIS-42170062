//
// Created by user on 16.10.2025.
//

#ifndef LABWORK2_EXHIBIT_H
#define LABWORK2_EXHIBIT_H
#include <string>

class Exhibit {
  public:
  Exhibit() = default;
  virtual ~Exhibit() = default;

  std::string GetExhibitCollection() const;
  std::string GetExhibitName() const;
  int GetExhibitNumberId() const;
  int GetExhibitFoundationYear() const;

  void SetExhibitCollection(std::string exhibitCollection);
  void SetExhibitName(std::string exhibitName);
  void SetExhibitNumberId(int number);
  void SetExhibitFoundationYear(int year);

  virtual std::string GetExhibitType() const = 0;

  protected:
  std::string collection_;
  std::string name_;
  int numberId_ = 0;
  int foundationYear_ = 0;
};

#endif //LABWORK2_EXHIBIT_H