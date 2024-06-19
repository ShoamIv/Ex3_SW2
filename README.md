קטאן:

לוח המשחק:
מורכב מ 19: Hexagon, כלומר משושים. כל משושה מכיל:

6 קודקודים(Point), 6 צלעות(Edge), משאב ומספר קוביה.

נשים לב כי הקודקוד והצלעות מורכבים מ int על צירי x,y.
הצלעות נבנות בצורה רקורסיבית, בעזרת הקודקודים.

דרכים ויישובים:

את הדרכים נבנה על ידי שני קודקודים או על ידי צלע(שני בנאים).
את היישובים נבנה על ידי קבלת id של משושה ובנוסף id של קודקוד(יוסבר בהמשך) או על ידי קודקוד יחיד(x,y)(שני בנאים).
את העיר נבנה על ידי קבלת יישוב.

נשים לב שבעת בניית דרך,יישוב ועיר נבדוק שקיימים כל המשאבים ושהבנייה חוקית(לעיר,יישוב ועיר בדיקות נפרדות).

מערכת המסחר:

כאשר משתמש רוצה לבצע מסחר, הוא ראשית מציע(פונקציה) ואם המשתמש שקיבל את ההצעה מאשר, נקרא לפונקציית המסחר.
ניתן לבצע מסחר בין קלפים ומשאבים כך ש: משאב ומשאב, משאב וקלף, קלף קלף.

קלפי פיתוח:

ראשית class deck אשר יוצר חפיסת קלפי פיתוח ובעזרת פונקציית בתחילת כל משחק נבצע shuffle.

בעת ששחקן קונה קלף פיתוח נרים את הקלף באינקס 0 ונסיר אותו מהערמה. נחזיר את הקלף האקראי אל השחקן.

כל קלף פיתוח יורש מהקלף הבסיסי וממש רק את מתודת action המבצעת את הפעולה הספיציפית לו.

נקודות נוספות:

בניית הלוח כלהלן:
הלוח מתקיים על ציר ה x,y כך ש:
קצוות הלוח: 
 -5<= x =<5
 -8<= y =<8 

 כאשר ניתן לגשת לבניית ישוביים ודרכים בשני שיטות: שיטה לפי point, ושיטה לפי id של משושה ונקודה כך:
 המשושים מסודרים מ -0 ל18, בסדר עולה, המתחיל מהמשושה השמאלי תחתון ביותר עד הימני עליון.
 המעבר מתקיים לפי שורה שורה כלומר לאחר שסיימנו מעבר על משושה, הבא אחריו יהיה המשושה הימני לו ובמקרה של סיום שורה נעלה למשושה השמאלי בשורה מעליו.
כעת נשים לב לסידור ה id של הקודקודים בכל משושה.
כל משושה מחזיק וקטור קודקודים, אשר מסודרים בסדר עולה לפי y ואז לפי x: 
Board.cpp :: comparePoints_Clock
וכך ניתן לגשת לכל קודקוד בכל משושה על ידי מספר id של המשושה ושל הקודקוד.

![catan_board](https://github.com/ShoamIv/Ex3_SW2/assets/155763643/19e9d323-fdd1-42f5-a129-2ca42da26705)



