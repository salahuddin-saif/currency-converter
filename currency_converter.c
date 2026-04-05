#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

string currentUser = "";
bool isLoggedIn = false;
int choice;


// =====loading page ====

void splashScreen()
{
    system("color 0A"); // green text
    system("cls");

    cout << R"(

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

)";
    cout << "\n\n\t\t\tPress ENTER to continue... \n";
   string dummy;
    getline(cin, dummy);  // wait for Enter
}

// ===== CENTER =====
void center(string text)
{
    int width = 80;
    int pad = (width - text.length()) / 2;
    for(int i = 0; i < pad; i++) cout << " ";
    cout << text << endl;
}

// ===== GLOBAL HEADER =====
void globalHeader()
{
    center("===============================================");
    center("     CURRENCY CONVERTER MANAGEMENT SYSTEM");
    center("===============================================");
}

// ===== PAGE HEADER =====
void pageHeader(string title, string color)
{
    system(color.c_str());
    system("cls");

    cout << "\n\n";
    globalHeader();
    cout << "\n";
    center(">> " + title + " <<");
    center("-----------------------------------------------");
    cout << "\n";
}

// ===== REGISTER =====
void registerUser()
{
    pageHeader("User Registration", "color E0");

    string u, p;

    center("Enter Username:");
    cout << "\t\t\t";
    cin >> u;

    center("Enter Password:");
    cout << "\t\t\t";
    cin >> p;

    ofstream file("users.txt", ios::app);
    file << u << " " << p << endl;
    file.close();

    center("Registration Successful!");
    system("pause");
}

// ===== LOGIN =====
void userLogin()
{
    pageHeader("User Login", "color E0");

    string u, p, fu, fp;
    bool found = false;

    center("Enter Username:");
    cout << "\t\t\t";
    cin >> u;

    center("Enter Password:");
    cout << "\t\t\t";
    cin >> p;

    ifstream file("users.txt");

    while(file >> fu >> fp)
    {
        if(u == fu && p == fp)
        {
            found = true;
            currentUser = u;
            isLoggedIn = true;
            break;
        }
    }

    file.close();

    if(found)
        center("Login Successful!");
    else
        center("Invalid Login!");

    system("pause");
}

// ===== SAVE HISTORY =====
void saveHistory(string conversion)
{
    ifstream in("history.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while(getline(in, line))
    {
        if(line.find("User: " + currentUser + " | " + conversion) != string::npos)
        {
            found = true;

            int pos = line.find("Total Uses: ");
            int count = stoi(line.substr(pos + 12));
            count++;

            temp << "User: " << currentUser
                 << " | " << conversion
                 << " | Total Uses: " << count << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    in.close();

    if(!found)
    {
        temp << "User: " << currentUser
             << " | " << conversion
             << " | Total Uses: 1" << endl;
    }

    temp.close();

    remove("history.txt");
    rename("temp.txt", "history.txt");
}

// ===== VIEW HISTORY =====
void viewHistory()
{
    pageHeader("Admin History Panel", "color 1F");

    ifstream file("history.txt");
    string line;

    while(getline(file, line))
    {
        center(line);
    }

    file.close();
    system("pause");
}

// ===== CONVERTER =====
void currencyConverter(string color)
{
    int from, to;
    double amount, result;
    string cur[] = {"", "USD", "BDT", "EUR","AUD","SGD","BND"};

    while(true)
    {
        pageHeader("Currency Converter", color);

        center("1. USD    2. BDT    3. EUR  4. AUD  5. SGD  6. BND   0. Back");
        center("Select FROM:");
        cout << "\t\t\t";
        cin >> from;

        if(from == 0) return;

        center("Select TO:");
        cout << "\t\t\t";
        cin >> to;

        center("Enter Amount:");
        cout << "\t\t\t";
        cin >> amount;

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
            system("pause");
            continue;
        }

        center("Result: " + to_string(result));

        string conversion = cur[from] + string(" to ") + cur[to];
        saveHistory(conversion);

        system("pause");
    }
}

// ===== USER DASHBOARD (AFTER LOGIN) =====
void userDashboard()
{
    int ch;

    do
    {
        pageHeader("User Dashboard", "color E0");

        center("1. Currency Converter");
        center("2. Logout");

        cout << "\t\t\t";
        cin >> ch;

        switch(ch)
        {
        case 1:
            currencyConverter("color E0");
            break;
        case 2:
            isLoggedIn = false;
            currentUser = "";
            center("Logged out successfully!");
            system("pause");
            return;
        }

    } while(true);
}

// ===== USER PANEL =====
void userPanel()
{
    int ch;

    while(true)
    {
        if(!isLoggedIn)
        {
            pageHeader("User Panel", "color E0");

            center("1. Register");
            center("2. Login");
            center("0. Back");

            cout << "\t\t\t";
            cin >> ch;

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
    pageHeader("Admin Login", "color 1F");

    char u[20], p[20];

    center("Username:");
    cout << "\t\t\t";
    cin >> u;

    center("Password:");
    cout << "\t\t\t";
    cin >> p;

    if(strcmp(u, "admin") == 0 && strcmp(p, "admin") == 0)
    {
        int ch;
        do
        {
            pageHeader("Admin Panel", "color 1F");

            center("1. Converter");
            center("2. View History");
            center("0. Exit");

            cout << "\t\t\t";
            cin >> ch;

            if(ch == 1) currencyConverter("color 1F");
            else if(ch == 2) viewHistory();
            else if(ch == 0) exit(0);

        } while(true);
    }
    else
    {
        center("Wrong Login!");
        system("pause");
    }
}

// ===== MAIN =====
int main()
{
    splashScreen();

    while(true)
    {
        pageHeader("Main Menu", "color 07");

        center("1. Admin");
        center("2. User");
        center("0. Exit");

        cout << "\t\t\t";
        cin >> choice;

        if(choice == 1) adminLogin();
        else if(choice == 2) userPanel();
        else if(choice == 0) exit(0);
    }
}
