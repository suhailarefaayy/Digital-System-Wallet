## Welcome to Cash It

### Project Overview

This project introduces a digital wallet system designed to facilitate secure financial transactions for users. It includes features tailored for both administrators and users, ensuring efficient management of accounts and transactions.

**User Requirements:**

**Administrator Functionality:**

1. **Record Management:** Administrators can perform various operations related to user accounts to ensure smooth management.
2. **Account Adjustment:** Administrators have the authority to adjust user account balances as needed.
3. **Transaction Monitoring:** Administrators can view registered users, their balances, transaction histories, and take necessary actions.

**User Functionality:**

1. **Account Creation:** Users can sign up for the digital wallet system by providing the necessary credentials for account creation.
2. **Financial Operations:** Users can perform various financial operations such as checking their current balance, sending money to others, requesting money from others, and managing their transaction histories.
3. **Profile Management:** Users can edit their profile information, including usernames and passwords.

**System Management:**

The system includes a CashIt module responsible for user authentication, registration, and interaction. It identifies users as either regular users or administrators, provides registration options, and manages data reading and writing tasks for user, admin, and transaction data.

**Transaction Handling:**

Transactions are managed through a dedicated class, ensuring smooth processing between users. Recent transaction details, including sender, receiver, amount, date, and time, are provided.

**File Handling:**

File handling functionalities are provided through the FileReader and FileWriter classes. These classes facilitate reading and writing user data, admin data, and transaction data to respective files, ensuring data persistence and system continuity.
