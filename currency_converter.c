#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char currentUser[100] = "";
int isLoggedIn = 0;
int choice;

// Function declarations
void splashScreen();
void center(char *text);
void globalHeader();
void pageHeader(char *title, char *color);
void registerUser();
void userLogin();
void saveHistory(char *conversion);
void viewHistory();
void currencyConverter(char *color);
void userDashboard();
void userPanel();
void adminLogin();
void developerPanel();

// ===== UTILITY FUNCTIONS =====
void clearScreen() {
    system("cls");
}

void waitForEnter() {
    printf("\n\t\t\tPress ENTER to continue...");
    while(getchar() != '\n');
    getchar();
}

// ===== loading page ====
void splashScreen()
{
    system("color 0A"); // green text
    clearScreen();

    printf(R"(
                     ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                   +++*#######################################################*++++
                 ++++#############################**############################*+++
                +++###############################::##############################++++
              +++*##################################################################++++
            ++++#==+###-+-####*+=-#+###+*##########++########*+#+#=###=#########*#+###++++
             ++*#-#:-+-.+-.+:-++-:#===.-=-==++*-.-=-==*::+:-===#-*:-#=::--==.*=-=*-+.**+++
              ++###################################################################***++
              +++###################################################################*++
               ++*#################################################################*+++
               +++#################################################################+++
                ++*############################*++=+*#############################*++
                +++########=*+++*#########*==++==--===+=-=#########=--+#+:########+++
                 ++##########++##*==*###=++=+-+++++++==-+++-+##+:-*####=+########*++
                 ++############*=*###*:+--+=++==-----+=++=+-=--#####*-+##########*++
                 ++###############=+*===++-==-+==+++===-+--++==-##=-#############+++
                 ++#################=::+=-=+++=-------++++--==-=.+###############+++
                 ++################==-=-.:+--+--=====--+--+-:.:--+###############+++
                 ++###############*+--+--===+=:::-+:::-+==::--+-+:###############+++
                +++###############++-==-=+=::::::-=:::::::+*--=-=-###############+++
                +++###############++-===#=:::::::-=::::::::+*-===-###############*++
               +++*###############++-=+*=::::::::-=::::::::==*=-+:################++
               +++#################===%==**=::--:++:*#+::**==*#-=-*###############+++
      ++++++   +++##############+.#*+%%%%%%%%%%%%%%%%%%%%%%%%%%*=##=.*############*++   +++++++
    +++++++++++++*############-*####+:--*++==-+---+---+-+=+++:.:######=-##########*++ ++++++++++
    +++++++++++++##########*:###+:####-+-+=-=+-+--+--+-+--+==-*##+.-####=-#########+++++++++++++
   +++++++++++++*#########-*.*##########=+=++-+=+=+-+=+-+=*:*#########+. .*########*+++++++++++++
  ++++++++++++++###########################:+**=-----+*+:+############*############*+++++++++++++
  ++++++++++++++##############...:+#############*##**#############*:...=###########*++++++++++++++
 +++++++++++++++#############:.......:#############################+....+##########*+++++++++++++++
++++++++++++++++*###########:...:#+....:##################+:..:#####=....*#########+++++++++++++++++
+++++++++++++++++##########=....*###:...=##################:...:#####-....*#######*+++++++++++++++++
  ++++++++++++++++########=....*####:...=#######::::=######*....-#####-...-######*++++++++++++++++
   ++++++++++++++++*#####*....=####:...:########....=#######*....-####*...:#####*+++++++++++++++
    +++++++++++++++++####:.....:--:....*########....=########+....:++-....*####+++++++++++++++++
    +++++++++++++++++++*####+:.......-##########....=#########*.........+###*+++++++++++++++++++
    ++++++++++++++++++++++*#####*++*############....=###########*===+*####*++++++++++++++++++++
    ++++++++++++++++++++++++*##################....=#################*+++++++++++++++++++++++
      ++++++++++++++++++++++++++++*#############....=#############*++++++++++++++++++++++++++
       ++++++++++++++++++++++++++++++++*########....=#######**++++++++++++++++++++++++++++++
         ++++++++++++++++++++++++++++++++++*############*+++++++++++++++++++++++++++++++++
           +++++++++++++++++++++++++++++++++++*######*++++++++++++++++++++++++++++++++++
             +++++++++++++++++++++++++++++++++++*#*+++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                      +++++++++++++++++++++++++*****+++++++++++++++++++++++++
                           +++++++++++++++++++********+++++++++++++++++++
                                +++++++++++++**********++++++++++++
                                     ++++++++*********+++++++++
                                         +++++*******++++++
                                            ++++++++++++
                                              ++++++++
                                                 ++

)");

    printf("\n\n\t\t\tPress ENTER to continue... \n");
    getchar();  // Only one getchar() now - waits for single Enter press
}

// ===== CENTER =====
void center(char *text)
{
    int width = 80;
    int pad = (width - strlen(text)) / 2;
    for(int i = 0; i < pad; i++) printf(" ");
    printf("%s\n", text);
}

// ===== GLOBAL HEADER =====
void globalHeader()
{
    center("===============================================");
    center("     CURRENCY CONVERTER MANAGEMENT SYSTEM");
    center("===============================================");
}

// ===== PAGE HEADER =====
void pageHeader(char *title, char *color)
{
    char command[50];
    sprintf(command, "color %s", color);
    system(command);
    clearScreen();

    printf("\n\n");
    globalHeader();
    printf("\n");
    char temp[100];
    sprintf(temp, ">> %s <<", title);
    center(temp);
    center("-----------------------------------------------");
    printf("\n");
}

// ===== DEVELOPER PANEL =====
void developerPanel()
{
    int ch;
    do
    {
        pageHeader("Developer Panel", "0E");

        center("===============================================");
        center("          DEVELOPER INFORMATION");
        center("===============================================");
        printf("\n");
        center("|------------------------------------------------|");
        center("|Developer: [NAME1]      |   Developer: [NAME2]  |");
        center("|ID:         [ID1]       |   ID:         [ID2]   |");
        center("|------------------------------------------------|");
        center("|Developer: [NAME3]      |   Developer: [NAME4]  |");
        center("|ID:         [ID3]       |   ID:         [ID4]   |");
        center("|------------------------------------------------|");
        center("|Developer: [NAME5]      |                       |");
        center("|ID:         [ID5]       |                       |");
        center("|------------------------------------------------|");
        printf("\n");
        center("Version: 1.0");
        center("Course: Programming and Problem Solving Lab");
        center("Submitted To: Abdullah Al Mamun");
        center("           Sr. Lecturer");
        center("            Department of CSE");
        center("              Daffodil International University");
        center("Date: 2026");
        printf("\n");

        center("===============================================");
        center("1. Back to Admin Panel");
        center("0. Exit");

        printf("\n\t\t\t");
        scanf("%d", &ch);

        if(ch == 1) return;
        else if(ch == 0) exit(0);

    } while(1);
}

// ===== REGISTER =====
void registerUser()
{
    pageHeader("User Registration", "E0");

    char u[100], p[100];

    center("Enter Username:");
    printf("\t\t\t");
    scanf("%s", u);

    center("Enter Password:");
    printf("\t\t\t");
    scanf("%s", p);

    FILE *file = fopen("users.txt", "a");
    fprintf(file, "%s %s\n", u, p);
    fclose(file);

    center("Registration Successful!");
    waitForEnter();
}

// ===== LOGIN =====
void userLogin()
{
    pageHeader("User Login", "E0");

    char u[100], p[100], fu[100], fp[100];
    int found = 0;

    center("Enter Username:");
    printf("\t\t\t");
    scanf("%s", u);

    center("Enter Password:");
    printf("\t\t\t");
    scanf("%s", p);

    FILE *file = fopen("users.txt", "r");

    while(fscanf(file, "%s %s", fu, fp) != EOF)
    {
        if(strcmp(u, fu) == 0 && strcmp(p, fp) == 0)
        {
            found = 1;
            strcpy(currentUser, u);
            isLoggedIn = 1;
            break;
        }
    }

    fclose(file);

    if(found)
        center("Login Successful!");
    else
        center("Invalid Login!");

    waitForEnter();
}

// ===== SAVE HISTORY =====
void saveHistory(char *conversion)
{
    FILE *in = fopen("history.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char line[500];
    int found = 0;

    char searchStr[500];
    sprintf(searchStr, "User: %s | %s", currentUser, conversion);

    if(in != NULL) {
        while(fgets(line, sizeof(line), in))
        {
            line[strcspn(line, "\n")] = 0; // Remove newline

            if(strstr(line, searchStr) != NULL)
            {
                found = 1;

                char *pos = strstr(line, "Total Uses: ");
                if(pos != NULL)
                {
                    int count = atoi(pos + 12);
                    count++;

                    fprintf(temp, "User: %s | %s | Total Uses: %d\n", currentUser, conversion, count);
                }
            }
            else
            {
                fprintf(temp, "%s\n", line);
            }
        }
        fclose(in);
    }

    if(!found)
    {
        fprintf(temp, "User: %s | %s | Total Uses: 1\n", currentUser, conversion);
    }

    fclose(temp);

    remove("history.txt");
    rename("temp.txt", "history.txt");
}

// ===== VIEW HISTORY =====
void viewHistory()
{
    pageHeader("Admin History Panel", "1F");

    FILE *file = fopen("history.txt", "r");
    char line[500];

    if(file == NULL) {
        center("No history available yet!");
    } else {
        while(fgets(line, sizeof(line), file))
        {
            line[strcspn(line, "\n")] = 0; // Remove newline
            center(line);
        }
        fclose(file);
    }

    waitForEnter();
}

// ===== CONVERTER =====
void currencyConverter(char *color)
{
    int from, to;
    double amount, result;
    char *cur[] = {"", "USD", "BDT", "EUR", "AUD", "SGD", "BND"};

    while(1)
    {
        pageHeader("Currency Converter", color);

        center("1. USD    2. BDT    3. EUR  4. AUD  5. SGD  6. BND   0. Back");
        center("Select FROM:");
        printf("\t\t\t");
        scanf("%d", &from);

        if(from == 0) return;

        center("Select TO:");
        printf("\t\t\t");
        scanf("%d", &to);

        center("Enter Amount:");
        printf("\t\t\t");
        scanf("%lf", &amount);

        if(from==1 && to==2) result = amount * 122.43;      // USD -> BDT
        else if(from==2 && to==1) result = amount / 122.43; // BDT -> USD
        else if(from==1 && to==3) result = amount * 0.87;   // USD -> EUR
        else if(from==3 && to==1) result = amount / 0.87;   // EUR -> USD
        else if(from==2 && to==3) result = amount / 0.0071; // BDT -> EUR
        else if(from==3 && to==2) result = amount * 0.0071; // EUR -> BDT
        else if(from==1 && to==4) result = amount * 1.45;   // USD -> AUD
        else if(from==4 && to==1) result = amount / 1.45;   // AUD -> USD
        else if(from==1 && to==5) result = amount * 1.29;   // USD -> SGD
        else if(from==5 && to==1) result = amount / 1.29;   // SGD -> USD
        else if(from==1 && to==6) result = amount * 1.29;   // USD -> BND
        else if(from==6 && to==1) result = amount / 1.29;   // BND -> USD
        else if(from==2 && to==4) result = amount / 84.25;  // BDT -> AUD
        else if(from==4 && to==2) result = amount * 84.25;  // AUD -> BDT
        else if(from==2 && to==5) result = amount / 95.26;  // BDT -> SGD
        else if(from==5 && to==2) result = amount * 95.26;  // SGD -> BDT
        else if(from==2 && to==6) result = amount / 95.29;  // BDT -> BND
        else if(from==6 && to==2) result = amount * 95.29;  // BND -> BDT
        else if(from==3 && to==4) result = amount * 1.67;   // EUR -> AUD
        else if(from==4 && to==3) result = amount / 1.67;   // AUD -> EUR
        else if(from==3 && to==5) result = amount * 1.48;   // EUR -> SGD
        else if(from==5 && to==3) result = amount / 1.48;   // SGD -> EUR
        else if(from==3 && to==6) result = amount * 1.48;   // EUR -> BND
        else if(from==6 && to==3) result = amount / 1.48;   // BND -> EUR
        else if(from==4 && to==5) result = amount * 0.89;   // AUD -> SGD
        else if(from==5 && to==4) result = amount / 0.89;   // SGD -> AUD
        else if(from==4 && to==6) result = amount * 0.88;   // AUD -> BND
        else if(from==6 && to==4) result = amount / 0.88;   // BND -> AUD
        else if(from==5 && to==6) result = amount * 1.0;    // SGD -> BND (1:1)
        else if(from==6 && to==5) result = amount / 1.0;    // BND -> SGD (1:1)
        else if(from == to) result = amount;
        else
        {
            center("Invalid Conversion!");
            waitForEnter();
            continue;
        }

        char resultMsg[200];
        sprintf(resultMsg, "Result: %.2lf", result);
        center(resultMsg);

        char conversion[50];
        sprintf(conversion, "%s to %s", cur[from], cur[to]);
        saveHistory(conversion);

        waitForEnter();
    }
}

// ===== USER DASHBOARD (AFTER LOGIN) =====
void userDashboard()
{
    int ch;

    do
    {
        pageHeader("User Dashboard", "E0");

        center("1. Currency Converter");
        center("2. Logout");

        printf("\t\t\t");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            currencyConverter("E0");
            break;
        case 2:
            isLoggedIn = 0;
            strcpy(currentUser, "");
            center("Logged out successfully!");
            waitForEnter();
            return;
        }

    } while(1);
}

// ===== USER PANEL =====
void userPanel()
{
    int ch;

    while(1)
    {
        if(!isLoggedIn)
        {
            pageHeader("User Panel", "E0");

            center("1. Register");
            center("2. Login");
            center("0. Back");

            printf("\t\t\t");
            scanf("%d", &ch);

            if(ch == 1) registerUser();
            else if(ch == 2)
            {
                userLogin();
                if(isLoggedIn)
                    userDashboard(); // go to dashboard
            }
            else if(ch == 0) return;
        }
    }
}

// ===== ADMIN LOGIN =====
void adminLogin()
{
    pageHeader("Admin Login", "1F");

    char u[20], p[20];

    center("Username:");
    printf("\t\t\t");
    scanf("%s", u);

    center("Password:");
    printf("\t\t\t");
    scanf("%s", p);

    if(strcmp(u, "admin") == 0 && strcmp(p, "admin") == 0)
    {
        int ch;
        do
        {
            pageHeader("Admin Panel", "1F");

            center("1. Converter");
            center("2. View History");
            center("3. Developer Options");
            center("0. Exit");

            printf("\t\t\t");
            scanf("%d", &ch);

            if(ch == 1) currencyConverter("1F");
            else if(ch == 2) viewHistory();
            else if(ch == 3) developerPanel();
            else if(ch == 0) exit(0);

        } while(1);
    }
    else
    {
        center("Wrong Login!");
        waitForEnter();
    }
}

// ===== MAIN =====
int main()
{
    splashScreen();

    while(1)
    {
        pageHeader("Main Menu", "07");

        center("1. Admin");
        center("2. User");
        center("0. Exit");

        printf("\t\t\t");
        scanf("%d", &choice);

        if(choice == 1) adminLogin();
        else if(choice == 2) userPanel();
        else if(choice == 0) exit(0);
    }

    return 0;
}
