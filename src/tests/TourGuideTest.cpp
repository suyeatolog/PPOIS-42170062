#include <gtest/gtest.h>
#include "../Tours/TourGuide/TourGuide.h"
#include "../Halls/ArtHall/ArtHall.h"
#include "../Halls/HistoryHall/HistoryHall.h"
#include "../Halls/JewelryHall/JewelryHall.h"
#include "../Visitor/Visitor.h"
#include "../Exceptions/Exceptions.h"

class TourGuideTest : public ::testing::Test {
protected:
    void SetUp() override {
        guide.SetName("Lila West");
        guide.SetEmployeeId(101);
        guide.SetSpecialization("ArtHall");
        guide.SetExperienceYears(5);
        guide.SetLanguages({"English", "Russian", "French"});

        artHall.SetHallName("Renaissance Gallery");
        artHall.SetHallNumber(1);

        historyHall.SetHallName("Ancient Civilizations");
        historyHall.SetHallNumber(2);

        jewelryHall.SetHallName("Royal Jewelry Collection");
        jewelryHall.SetHallNumber(3);

        visitor1.SetVisitorName("Eduard Kichigin");
        visitor2.SetVisitorName("Dexter Morgan");
        visitor3.SetVisitorName("Eugene Kulik");
    }

    TourGuide guide;
    ArtHall artHall;
    HistoryHall historyHall;
    JewelryHall jewelryHall;
    Visitor visitor1;
    Visitor visitor2;
    Visitor visitor3;
};

TEST_F(TourGuideTest, GettersTest) {
    EXPECT_EQ(guide.GetName(), "Lila West");
    EXPECT_EQ(guide.GetEmployeeId(), 101);
    EXPECT_EQ(guide.GetSpecialization(), "ArtHall");
    EXPECT_EQ(guide.GetExperienceYears(), 5);
    EXPECT_EQ(guide.GetToursCount(), 0);
    EXPECT_TRUE(guide.GetIsAvailable());

    auto languages = guide.GetLanguages();
    EXPECT_EQ(languages.size(), 3);
    EXPECT_EQ(languages[0], "English");
    EXPECT_EQ(languages[1], "Russian");
    EXPECT_EQ(languages[2], "French");
}

TEST_F(TourGuideTest, CreateTourTest) {
    guide.CreateTour("Art Masterpieces", "Renaissance to Modern");

    Tour* tour = guide.GetCurrentTour();
    EXPECT_NE(tour, nullptr);
    EXPECT_EQ(tour->GetTourName(), "Art Masterpieces");
    EXPECT_EQ(tour->GetTheme(), "Renaissance to Modern");
    EXPECT_TRUE(guide.GetIsAvailable());
}

TEST_F(TourGuideTest, StartAndEndTourTest) {
    guide.CreateTour("Art Tour", "Renaissance");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor1);

    guide.StartTour();

    EXPECT_FALSE(guide.GetIsAvailable());
    EXPECT_EQ(guide.GetToursCount(), 0);

    Tour* activeTour = guide.GetCurrentTour();
    EXPECT_NE(activeTour, nullptr);
    EXPECT_TRUE(activeTour->IsActive());

    guide.EndTour();

    EXPECT_TRUE(guide.GetIsAvailable());
    EXPECT_EQ(guide.GetToursCount(), 1);
    EXPECT_EQ(guide.GetCurrentTour(), nullptr);
}

TEST_F(TourGuideTest, MultipleToursTest) {
    guide.CreateTour("First Tour", "Art");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor1);
    guide.StartTour();
    guide.EndTour();

    EXPECT_EQ(guide.GetToursCount(), 1);

    guide.CreateTour("Second Tour", "Art History");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor2);
    guide.StartTour();
    guide.EndTour();

    EXPECT_EQ(guide.GetToursCount(), 2);
    EXPECT_TRUE(guide.GetIsAvailable());
}

TEST_F(TourGuideTest, LanguagesManagementTest) {
    EXPECT_TRUE(guide.SpeaksLanguage("English"));
    EXPECT_TRUE(guide.SpeaksLanguage("French"));
    EXPECT_FALSE(guide.SpeaksLanguage("Spanish"));

    guide.AddLanguage("Spanish");
    EXPECT_TRUE(guide.SpeaksLanguage("Spanish"));

    guide.RemoveLanguage("French");
    EXPECT_FALSE(guide.SpeaksLanguage("French"));

    auto languages = guide.GetLanguages();
    EXPECT_EQ(languages.size(), 3);
}

TEST_F(TourGuideTest, CanGuideHallMethodTest) {
    TourGuide artGuide;
    artGuide.SetSpecialization("ArtHall");

    TourGuide historyGuide;
    historyGuide.SetSpecialization("HistoryHall");

    TourGuide jewelryGuide;
    jewelryGuide.SetSpecialization("JewelryHall");

    TourGuide generalGuide;
    generalGuide.SetSpecialization("General");

    EXPECT_TRUE(artGuide.CanGuideHall(&artHall));
    EXPECT_FALSE(artGuide.CanGuideHall(&historyHall));
    EXPECT_FALSE(artGuide.CanGuideHall(&jewelryHall));

    EXPECT_TRUE(historyGuide.CanGuideHall(&historyHall));
    EXPECT_FALSE(historyGuide.CanGuideHall(&artHall));
    EXPECT_FALSE(historyGuide.CanGuideHall(&jewelryHall));

    EXPECT_TRUE(jewelryGuide.CanGuideHall(&jewelryHall));
    EXPECT_FALSE(jewelryGuide.CanGuideHall(&artHall));
    EXPECT_FALSE(jewelryGuide.CanGuideHall(&historyHall));

    EXPECT_TRUE(generalGuide.CanGuideHall(&artHall));
    EXPECT_TRUE(generalGuide.CanGuideHall(&historyHall));
    EXPECT_TRUE(generalGuide.CanGuideHall(&jewelryHall));

    EXPECT_FALSE(artGuide.CanGuideHall(nullptr));
}

TEST_F(TourGuideTest, TourSuccessRate) {
    EXPECT_DOUBLE_EQ(guide.CalculateTourSuccessRate(), 0.0);

    guide.CreateTour("Tour 1", "Theme 1");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor1);
    guide.StartTour();
    guide.EndTour();

    EXPECT_DOUBLE_EQ(guide.CalculateTourSuccessRate(), 1.0);

    guide.CreateTour("Tour 2", "Theme 2");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor2);
    guide.StartTour();

    EXPECT_DOUBLE_EQ(guide.CalculateTourSuccessRate(), 0.5);
}

TEST_F(TourGuideTest, GuideExceptionsTest) {
    guide.CreateTour("First Tour", "Art");
    guide.AddHallToRoute(&artHall);
    guide.AddVisitorToTour(&visitor1);
    guide.StartTour();

    EXPECT_THROW(guide.CreateTour("Second Tour", "History"), TourGuideNotAvailableException);

    guide.EndTour();

    EXPECT_THROW(guide.StartTour(), InvalidTourParametersException);

    EXPECT_THROW(guide.AddHallToRoute(&artHall), InvalidTourParametersException);

    EXPECT_THROW(guide.AddVisitorToTour(&visitor1), InvalidTourParametersException);

    EXPECT_THROW(guide.MoveToNextHall(), InvalidTourParametersException);

    EXPECT_THROW(guide.EndTour(), InvalidTourParametersException);
}

TEST_F(TourGuideTest, SpecializationMismatchExceptionTest) {
    guide.CreateTour("Jewelry Tour", "Royal Collection");

    EXPECT_THROW(guide.AddHallToRoute(&jewelryHall), GuideSpecializationMismatchException);
}

TEST_F(TourGuideTest, MoveThroughTourHallsTest) {
    guide.SetSpecialization("General");
    guide.CreateTour("Multi-Hall Tour", "Various");
    guide.AddHallToRoute(&artHall);
    guide.AddHallToRoute(&historyHall);
    guide.AddVisitorToTour(&visitor1);

    guide.StartTour();

    Tour* tour = guide.GetCurrentTour();
    EXPECT_NE(tour, nullptr);
    EXPECT_EQ(tour->GetCurrentHallIndex(), 0);

    guide.MoveToNextHall();
    EXPECT_EQ(tour->GetCurrentHallIndex(), 1);

    guide.EndTour();
}

TEST_F(TourGuideTest, AddHallToRouteWithCanGuideHallTest) {
    guide.CreateTour("Art Tour", "Renaissance");

    EXPECT_NO_THROW(guide.AddHallToRoute(&artHall));

    EXPECT_THROW(guide.AddHallToRoute(&historyHall), GuideSpecializationMismatchException);

    EXPECT_THROW(guide.AddHallToRoute(&jewelryHall), GuideSpecializationMismatchException);
}

TEST_F(TourGuideTest, GeneralGuideCanGuideAllHallsTest) {
    TourGuide generalGuide;
    generalGuide.SetSpecialization("General");
    generalGuide.CreateTour("General Tour", "All Collections");

    EXPECT_NO_THROW(generalGuide.AddHallToRoute(&artHall));
    EXPECT_NO_THROW(generalGuide.AddHallToRoute(&historyHall));
    EXPECT_NO_THROW(generalGuide.AddHallToRoute(&jewelryHall));
}