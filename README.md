// Roniki04@gmail.com

# README - משחק Catan

## חוקי המשחק שהגדרנו
במשחק Catan שלנו, כל שחקן מתחיל עם הנחת שני ישובים ושני כבישים. המשחק מתנהל בתורות כאשר כל שחקן זורק קוביה בתורו ואוסף משאבים בהתאם למיקומם על הלוח. שחקנים יכולים לסחור במשאבים, לבנות ישובים, כבישים ולקנות קלפי פיתוח. המשחק מסתיים כאשר אחד השחקנים מגיע ל-10 נקודות.

## היררכיית המחלקות
- `Vertex`: מייצגת קודקוד בלוח המשחק עם מזהה, שכנים, וכבישים שכנים.
- `Edge`: מייצגת קצה בלוח המשחק עם מזהה, קודקודים שכנים, וקצוות שכנים.
- `Player`: מייצגת שחקן במשחק עם משאבים, נקודות, ושיטות לפעולות שונות.
- `Board`: מייצגת את לוח המשחק עם קודקודים וקצוות.

## ספריות בהן השתמשנו
- `<vector>`: לשימוש במבני נתונים דינאמיים.
- `<string>`: לשימוש במחרוזות.

## תיאור השיטות שכתבנו
- `Player::placeSettlement(Vertex vertex, Board& gameBoard)`: מניחה ישוב על הקודקוד המצויין.
- `Player::placeRoad(Edge edge, Board& gameBoard)`: מניחה כביש על הקצה המצויין.
- `Player::rollDice()`: זורקת קוביה ומחלקת משאבים בהתאם לתוצאה.
- `Player::endTurn()`: מסיימת את תור השחקן.
- `Player::trade(Player& tradeWith, std::string resourceGive, std::string resourceGet, int amountGive, int amountGet)`: סחר במשאבים עם שחקן אחר.
- `Player::buyDevelopmentCard()`: קונה קלף פיתוח.
- `Player::printPoints()`: מדפיסה את מספר הנקודות של השחקן.
- `Player::throwHalf(std::vector<int> cardsBuy)`: זורקת חצי מהקלפים שהשחקן מחזיק.

## תוכנית main המריצה סיבוב תקין של המשחק

התוכנית הראשית (Demo.cpp) מראה דוגמה לסיבוב משחק. התוכנית כוללת:
- יצירת שחקנים.
- התחלת המשחק עם הנחת שני ישובים ושני כבישים לכל שחקן.
- זריקת קוביה וחלוקת משאבים.
- פעולות שונות כמו סחר, בניית כבישים וקניית קלפי פיתוח.
- סיום המשחק והכרזת המנצח.


-----------------------------------------

היררכיית המחלקות
Vertex: מייצגת קודקוד בלוח המשחק עם מזהה, שכנים, וכבישים שכנים.
Edge: מייצגת קצה בלוח המשחק עם מזהה, קודקודים שכנים, וקצוות שכנים.
Player: מייצגת שחקן במשחק עם משאבים, נקודות, ושיטות לפעולות שונות.
Board: מייצגת את לוח המשחק עם קודקודים וקצוות.
Card: מייצגת קלף במשחק עם סוג והפעלה.
Catan: מייצגת את המשחק עצמו, עם לוח, שחקנים וקלפים.
KnightCard: מייצגת קלף אביר.
PromotionCard: מייצגת קלף קידום עם סוגים שונים.
VictoryPointCard: מייצגת קלף נקודת ניצחון.
Meshushe: מייצגת משושה בלוח המשחק עם קודקודים, מזהה וסוג משאב.
Resource: מייצגת את המשאבים במשחק (עץ, לבנה, צמר, חיטה, אבן).


תיאור השיטות שכתבנו
Board:
printBoard(): מדפיסה את הלוח.
initialize(): מאתחלת את הלוח.
defineEdgeAndVertex(): מגדירה את הקודקודים והקצוות בלוח.
isVertexEmpty(int vertexIndex) const: בודקת אם הקודקוד פנוי להנחת יישוב או עיר.
isEdgeEmpty(int edgeIndex) const: בודקת אם הצלע פנויה להנחת דרך.
placeSettlement(int vertexIndex): מניחה יישוב על הקודקוד .
placeCity(int vertexIndex): מניחה עיר על הקודקוד .
placeRoad(int edgeIndex): מניחה דרך על הצלע .
setVertex(int placeNum): מגדירה את הקודקוד.
setEdge(int placeNum): מגדירה את הצלע.

Player:
getPlayerName() const: מחזירה את שם השחקן.
getPointsOfPlayer() const: מחזירה את מספר הנקודות של השחקן.
rollDice(std::vector<Player*>& players, Board& board): זורקת קוביה ומחלקת משאבים בהתאם לתוצאה.
endTurn(): מסיימת את תור השחקן.
trade(Player& tradeWith, std::string resourceGive, int amountGive, std::string resourceGet, int amountGet): סחר במשאבים עם שחקן אחר.
buyDevelopmentCard(std::vector<Player*>& players, Card* card): קונה קלף פיתוח.
printPoints(): מדפיסה את מספר הנקודות של השחקן.
throwHalf(): זורקת חצי מהקלפים שהשחקן מחזיק.
randomCard(std::vector<Card*>& listCard): מחזירה קלף אקראי.
placeSettlement(Board& board, int index): מניחה יישוב על הלוח.
placeCity(Board& board, int index): מניחה עיר על הלוח.
placeRoad(Board& board, int index): מניחה דרך על הלוח.

Card:
use(): מפעילה את הקלף.
getType(): מחזירה את סוג הקלף.

Catan:
setPlayer(int index, Player& player): מגדירה שחקן.
getPlayer(int index): מחזירה שחקן לפי אינדקס.
setBoard(const Board& board): מגדירה את הלוח.
getBoard(): מחזירה את הלוח.
setCard(int index, Card* card): מגדירה קלף.
getCard(int index): מחזירה קלף לפי אינדקס.
ChooseStartingPlayer(): בוחרת את השחקן ההתחלתי.
firstPlayer(): מחזירה את שם השחקן הראשון.
printWinner(): מדפיסה את שם המנצח.

Edge:
isRoad(): בודקת אם ניתן לבנות דרך.
placeRoad(): מניחה דרך.
setId(int edgeId): מגדירה את מזהה הצלע.
getId() const: מחזירה את מזהה הצלע.

Meshushe:
Meshushe(int id, std::string resourceType, Vertex vertex[6]): בונה את המשושה עם מזהה, סוג משאב וקודקודים.

Vertex:
buySettelment(const Vertex& vertex): בודקת אם ניתן לקנות יישוב.
buyCity(const Vertex& vertex): בודקת אם ניתן לקנות עיר.
isSettelment() const: בודקת אם יש יישוב בקודקוד.
isCity() const: בודקת אם יש עיר בקודקוד.
placeSettlement(): מניחה יישוב.
placeCity(): מניחה עיר.
setId(int vertexId): מגדירה את מזהה הקודקוד.
getId() const: מחזירה את מזהה הקודקוד.
getResourceType() const: מחזירה את סוג המשאב של הקודקוד.

Resource:
getResourceAmount(const std::string& resourceType) const: מחזירה את כמות המשאב.
incrementResource(const std::string& resourceType, int amount): מגדילה את כמות המשאב.

PromotionCard:
use(): מפעילה את קלף הקידום.

KnightCard:
use(): מפעילה את קלף האביר.

VictoryPointCard:
use(): מפעילה את קלף נקודת הניצחון.

monopolyCard, buildRoadCard, plentyYearCard:
use(): מפעילה את קלפי הקידום הספציפיים.

