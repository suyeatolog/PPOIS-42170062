# Предметная область музей на С++

Exhibit 4 9 → AncientTool, Armor, Book, CeramicVase, Coin, Costume, Fossil, HandmadeTowel, Jewelry, Painting, Sculpture, WorldWarIIArtifact \
AncientTool 6 14 → \
Armor 8 18 → \
Book 6 14 → \
CeramicVase 9 20 → \
Coin 11 23 → \
Costume 8 18 → \
Fossil 11 24 → \
HandMadeTowel 10 22 → \
Jewelry 8 18 → \
Painting 9 20 → \
Sculpture 11 23 → \
WorldWarIIArtifact 8 18 → \
Exhibition 3 9 → Exhibit \
Hall 5 12 → ArchaeologicalHall, ArmorHall, ArtHall, CeramicHall, CostumeHall, HistoryHall, JewelryHall, NumismaticsHall, WarHall, Exhibition \
ArchaeologicalHall 6 15 → Exhibition \
ArmorHall 6 15 → Exhibition \
ArtHall 6 15 → Exhibition \
CeramicHall 6 15 → Exhibition \
CostumeHall 6 15 → Exhibition \
HistoryHall 6 15 → Exhibition \
JewelryHall 6 15 → Exhibition \
NumismaticsHall 6 15 → Exhibition \
WarHall 6 15 → Exhibition \
Visitor 6 12 → \
Tour 8 27 → Hall, Visitor \
TourGuide 9 24 → Tour \
Ticket 3 6 → \
TicketWindow 2 4 → Visitor, Ticket \
Guard 2 5 → Visitor, TicketWindow \
Checkpoint 1 5 → Visitor, Guard, TicketWindow 


Exceptions(19)
Exception 1 1 → \
NoTicketsAvailableException 0 0 → \
InvalidTicketPriceException 0 0 → \
NoTicketException 0 0 → \
InvalidAgeException 0 0 → \
EmptyNameException 0 0 → \
TourException 0 0 → \
EmptyTourRouteException 0 0 → \
TourFullException 0 0 → \
TourNotActiveException 0 0 → \
InvalidTourParameterException 0 0 → \
TourGuideException 0 0 → \
TourGuideNotAvailableException 0 0 → \
TourAlreadyInProgressException 0 0 → \
InvalidTourParametersException 0 0 → \
GuideSpecializationMismatchException 0 0 → \
InvalidVisitorParameterException 0 0 → \
FullParticipantsException 0 0 → \
VisitorAlreadyRegistered 0 0 → 

Поля: 208

Поведения: 263 / 70+

Ассоциации: 30+

Исключения: 19