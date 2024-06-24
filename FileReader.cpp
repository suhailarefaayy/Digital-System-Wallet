#include "FileReader.h"

using namespace std;
const string userFiles = "Users.txt";
const string adminFiles = "Admins.txt";
const string allTransactionFiles = "AllTransactions.txt";
datee FileReader::parseDate(const string& dateStr) {
    datee d;
    sscanf_s(dateStr.c_str(), "%d-%d-%d", &d.day, &d.month, &d.year);
    return d;
} // Function to parse time string and initialize timee struct
timee FileReader::parseTime(const string& timeStr) {
    timee t;
    sscanf_s(timeStr.c_str(), "%d-%d", &t.hours, &t.minutes);
    return t;
}
void FileReader::readUserDataFromFile(unordered_map<string, User>& users)
{
    ifstream inputFile(userFiles);
    if (!inputFile.is_open()) {
        cout << "Unable to open file";
    }
    string line;
    while (getline(inputFile, line)) {
        User newUser;
        stringstream ss(line);
        string token;
        // Parse comma-separated values from the line
        getline(ss, newUser.username, ',');
        getline(ss, newUser.password, ',');
        string nationalIdStr;
        getline(ss, nationalIdStr, ',');
        newUser.nationalId = stoll(nationalIdStr);
        string balanceStr;
        getline(ss, balanceStr, ',');
        newUser.balance = stof(balanceStr);
        string suspendedStr;
        getline(ss, suspendedStr, ',');
        newUser.suspended = (suspendedStr == "True");
        string authorizedStr;
        getline(ss, authorizedStr, ',');
        newUser.authorized = (authorizedStr == "True");
        // Parse transactions
        string transactionsStr;
        getline(ss, transactionsStr, ',');
        stringstream transactionsStream(transactionsStr);
        string transactionToken;
        while (getline(transactionsStream, transactionToken, ';')) {
            stringstream transactionSS(transactionToken);
            Transactions transaction;
            getline(transactionSS, transaction.sender, ':');
            getline(transactionSS, transaction.reciever, ':');
            string amountStr;
            getline(transactionSS, amountStr, ':');
            transaction.amount = stof(amountStr);
            string dateStr;
            getline(transactionSS, dateStr, ':');
            transaction.date = parseDate(dateStr);
            string timeStr;
            getline(transactionSS, timeStr, ':');
            transaction.time = parseTime(timeStr);
            newUser.transactions.push_back(transaction);
        }
        string requestsStr;
        getline(ss, requestsStr, ',');
        stringstream requestsStream(requestsStr);
        string requestToken;
        while (getline(requestsStream, requestToken, ';')) {
            stringstream requestSS(requestToken);
            Requests request;
            string requestAmountStr;
            getline(requestSS, requestAmountStr, ':');
            request.requestAmount = stof(requestAmountStr);
            getline(requestSS, request.requester, ':');
            getline(requestSS, request.reciever, ':');
            newUser.requests.push_back(request);
        }
        users[newUser.username] = newUser;
    }
    inputFile.close();
}
void FileReader::readAdminDataFromFile(unordered_map<string, Admin>& admins)
{
    ifstream file(adminFiles);

    // Check if file is opened successfully
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file!" << endl;
    }
    string line;
    while (getline(file, line))
    {
        // Create a string stream to split the line by comma
        stringstream ss(line);
        string username, password;
        // Read username and password from the stringstream separated by comma
        getline(ss, username, ',');
        getline(ss, password, ',');
        // Output the username and password
        Admin newAdmin(username, password);
        admins[username] = newAdmin;
    }
    // Close the file
    file.close();

}
void FileReader::readTransactionDataFromFile(stack<Transactions>& transactions)
{
    ifstream file(allTransactionFiles);

    // Check if file is opened successfully
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;

    }
    string line;

    // Read each line in the file
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        // Split the line by comma
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // Create a transaction object and populate its fields
        Transactions transaction;
        transaction.sender = tokens[0];
        transaction.reciever = tokens[1];
        transaction.amount = stof(tokens[2]);
        transaction.date = parseDate(tokens[3]);
        transaction.time = parseTime(tokens[4]);

        // Store the transaction object in the vector
        transactions.push(transaction);
    }
    // Close the file
    file.close();
}