#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class PostNode
{
public:
    string content;
    string timestamp;
    PostNode* next;

    PostNode(string txt) {
        this->content = txt;
        next = nullptr;
    }
};

class PostStack
{
private:
    PostNode* top;

public:
    PostStack() {
        top = nullptr;

    }

    void push(string content)
    {
        PostNode* newNode = new PostNode(content);
        newNode->next = top;
        top = newNode;
    }
    bool isEmpty() const
    {
        return top == nullptr;
    }

    void display()
    {
        if (!top)
        {
            cout << "No posts available the stack is empty \n";
            return;
        }
        PostNode* current = top;
        while (current)
        {
            cout << "\n  " << current->content << "\n";
            current = current->next;
        }
    }
};

class QueueNode
{
public:
    string content;
    QueueNode* next;

    QueueNode(string txt) {
        this->content = txt;
        next = nullptr;

    }
};

class RequestQueue
{
private:
    QueueNode* front;
    QueueNode* rear;

public:
    RequestQueue() {
        front = nullptr;
        rear = nullptr;

    }

    void enqueue(string content)
    {
        QueueNode* newNode = new QueueNode(content);

        if (!rear)
        {
            front = rear = newNode;
        }

        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty\n";
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (!front)
            rear = nullptr;
    }

    void display()
    {
        if (!front)
        {
            cout << "Queue is empty\n";
            return;
        }
        QueueNode* current = front;
        while (current)
        {
            cout << "- " << current->content << "\n";
            current = current->next;
        }
    }
};
class MessageNode
{
public:
    string sender;
    string content;
    string timestamp;
    MessageNode* next;

    MessageNode(string sndr, string txt) {
        this->sender = sndr;
        this->content = txt;

        next = nullptr;
    }
};

class MessageStack
{
private:
    MessageNode* top;

public:
    MessageStack() {
        top = nullptr;
    }

    void push(string sender, string content)
    {
        MessageNode* newNode = new MessageNode(sender, content);
        newNode->next = top;
        top = newNode;
    }

    void display(const string& currentUser, const string& withUser)
    {
        if (!top)
        {
            cout << "No messages available.\n";
            return;
        }

        MessageNode* current = top;
        bool foundMessages = false;
        const int consoleWidth = 80;

        while (current)
        {
            if (current->sender == currentUser || current->sender == withUser)
            {
                foundMessages = true;
                if (current->sender == currentUser)
                {
                    cout << setw(consoleWidth) << "\n You: " << current->content << "\n";
                }

                else if (current->sender == withUser)
                {
                    cout << "  " << current->sender << " : " << current->content << "\n";
                }
            }
            current = current->next;
        }

        if (!foundMessages)
        {
            cout << "No messages with " << withUser << ".\n";
        }
    }
};

class User
{
public:
    string name;
    string password;
    string city;
    PostStack posts;
    MessageStack messages;
    RequestQueue friendRequests;
    RequestQueue notifications;
    User* next;
    User* friendList;

    User(string nm, string pwd, string ct) {
        this->name = nm;
        this->password = pwd;
        this->city = ct;
        next = nullptr;
        friendList = nullptr;
    }
};

class BST_implementation
{
public:
    User* user;
    BST_implementation* left;
    BST_implementation* right;

    BST_implementation(User* u) {
        this->user = u;
        left = nullptr;
        right = nullptr;
    }
};

class UserGraph
{
private:
    User* head;
    BST_implementation* root;
    User* currentUser;

    BST_implementation* insertUser(BST_implementation* node, User* newUser)
    {
        if (node == nullptr)
        {
            return new BST_implementation(newUser);
        }

        if (newUser->name < node->user->name)
        {
            node->left = insertUser(node->left, newUser);
        }

        else if (newUser->name > node->user->name)
        {
            node->right = insertUser(node->right, newUser);
        }
        return node;
    }

    User* searchUserBST(BST_implementation* node, string name, bool showMessage = true)
    {
        if (node == nullptr)
        {
            if (showMessage)
            {
                cout << " not found :(" << endl;
            }
            return nullptr;
        }

        if (name == node->user->name)
        {
            cout << "User Found :) : " << node->user->name << endl;
            return node->user;
        }

        else if (name < node->user->name)
        {
            cout << "Searching......." << endl;
            return searchUserBST(node->left, name);
        }

        else
        {
            cout << "Searching......." << endl;
            return searchUserBST(node->right, name);
        }
    }

    void displayBST(BST_implementation* node)
    {
        if (node == nullptr)
        {
            return;
        }
        displayBST(node->left);
        cout << node->user->name << "\n";
        displayBST(node->right);
    }

public:
    UserGraph() {
        head = nullptr;
        root = nullptr;
        currentUser = nullptr;

    }

    void addUser(string name, string password, string city)
    {
        if (searchUserBST(root, name, false))
        {
            cout << "User already exists.\nTry Logging In\n";
            return;
        }
        User* newUser = new User(name, password, city);

        newUser->next = head;
        head = newUser;

        root = insertUser(root, newUser);

        cout << "User " << name << " added successfully.\n";
    }

    User* searchUser(string name)
    {
        return searchUserBST(root, name);
    }


    bool login(string name, string password)
    {
        if (currentUser)
        {
            cout << "Error: A user is already logged in. Please logout first.\n";
            return false;
        }

        User* user = searchUser(name);
        if (!user || user->password != password)
        {
            cout << "Error: Invalid username or password.\n";
            return false;
        }

        currentUser = user;
        cout << "Welcome " << currentUser->name << "!\n";
        return true;
    }

    void logout()
    {
        if (!currentUser)
        {
            cout << "Error: No user is currently logged in.\n";
            return;
        }

        cout << "Goodbye, " << currentUser->name << "!\n";
        currentUser = nullptr;
    }

    User* getCurrentUser()
    {
        return currentUser;
    }

    void sendFriendRequest(string to)
    {
        if (!currentUser)
        {
            cout << "Error: Please login to send friend requests.\n";
            return;
        }
        User* recipient = searchUser(to);

        if (!recipient)
        {
            cout << "Invalid recipient.\n";
            return;
        }

        recipient->friendRequests.enqueue(currentUser->name + " sent you a friend request.");
        cout << "Friend request sent from " << currentUser->name << " to " << to << ".\n";
    }

    void acceptFriendRequest(string friendName)
    {
        if (!currentUser)
        {
            cout << "Error: Please login to accept friend requests.\n";
            return;
        }

        User* friendUser = searchUser(friendName);

        if (!friendUser)
        {
            cout << "Invalid friend name.\n";
            return;
        }

        char decision;
        cout << "Do you want to accept the friend request from " << friendName << "? (y/n): ";
        cin >> decision;

        if (decision == 'y')
        {
            User* newFriendNode = new User(friendName, "", "");
            newFriendNode->next = currentUser->friendList;
            currentUser->friendList = newFriendNode;

            User* newUserNode = new User(currentUser->name, "", "");
            newUserNode->next = friendUser->friendList;
            friendUser->friendList = newUserNode;

            currentUser->notifications.enqueue(friendName + " accepted your friend request.");
            cout << currentUser->name << " and " << friendName << " are now friends.\n";
        }

        else if (decision == 'n')
        {
            cout << "You have declined the friend request from " << friendName << ".\n";
        }

        else
        {
            cout << "Invalid input. Friend request remains pending.\n";
        }
    }

    void displayFriends(string name)
    {
        User* user = searchUser(name);

        if (!user)
        {
            cout << "User not found.\n";
            return;
        }

        cout << "Friends of " << name << ":\n";
        User* current = user->friendList;

        while (current)
        {
            cout << "- " << current->name << "\n";
            current = current->next;
        }
    }

    void displayFollowerPosts()
    {
        if (currentUser == nullptr)
        {
            cout << "Please login to view follower posts.\n";
            return;
        }

        User* friendNode = currentUser->friendList;
        bool hasPosts = false;

        cout << "Posts from your friends:\n";

        while (friendNode)
        {
            cout << "\nChecking friend: " << friendNode->name << "\n";

            User* friendUser = searchUser(friendNode->name);

            if (friendUser)
            {
                cout << "Found friend: " << friendUser->name << "\n";

                if (!friendUser->posts.isEmpty())
                {
                    cout << "Posts by " << friendUser->name << ":\n";
                    friendUser->posts.display();
                    hasPosts = true;
                }

                else
                {
                    cout << "No posts available for " << friendUser->name << ".\n";
                }
            }

            else
            {
                cout << "Error: Could not retrieve user " << friendNode->name << ".\n";
            }

            friendNode = friendNode->next;
        }

        if (!hasPosts)
        {
            cout << "None of your friends have posted yet.\n";
        }
    }
};

int main()
{
    UserGraph userGraph;
    string name, password, city, friendName, content, recipient, message;
    char choice;
    string log_name = "";
    bool isLoggedIn = false;
    User* recipientUser;


    while (true)
    {
        cout << "\n======================== Mini-Instagram ========================\n";
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "================================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1': {
            cout << "\n--- Signup ---\n";
            cout << "Enter username: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter city: ";
            cin >> city;
            userGraph.addUser(name, password, city);
            cout << "\nAccount created successfully!\n";
            break;
        }
        case '2': {
            cout << "\n--- Login ---\n";
            cout << "Enter username: ";
            cin >> name;
            log_name = name;
            cout << "Enter password: ";
            cin >> password;

            isLoggedIn = userGraph.login(name, password);
            if (isLoggedIn) {
                cout << "\nLogin successful! Welcome, " << log_name << ".\n";
            }
            else {
                cout << "\nInvalid username or password. Try again.\n";
            }
            break;
        }
        case '3':
            cout << "\nThank you for using Mini-Instagram! Exiting now.\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please select a valid option.\n";
            break;
        }

        while (isLoggedIn)
        {
            cout << "\n======================== Instagram Menu ========================\n";
            cout << "Instagram ID: " << log_name << "\n";
            cout << "1. Logout\n";
            cout << "2. Send Friend Request\n";
            cout << "3. Accept Friend Request\n";
            cout << "4. Post Content\n";
            cout << "5. View Friends/Followers Posts\n";
            cout << "6. Send Messages\n";
            cout << "7. View Messages\n";
            cout << "8. View Friend Requests\n";
            cout << "9. View Notifications\n";
            cout << "A. Display Friends\n";
            cout << "B. News Feeds (Personal Posts)\n";
            cout << "C. Search Users\n";
            cout << "================================================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case '1':
                userGraph.logout();
                isLoggedIn = false;
                cout << "\nYou have logged out successfully.\n";
                break;

            case '2':
                cout << "\nEnter friend's username: ";
                cin >> friendName;
                userGraph.sendFriendRequest(friendName);
                break;

            case '3':
                cout << "\nEnter friend's username to accept: ";
                cin >> friendName;
                userGraph.acceptFriendRequest(friendName);
                break;

            case '4':
                cout << "\nEnter post content: ";
                cin.ignore();
                getline(cin, content);
                if (userGraph.getCurrentUser() != nullptr)
                {
                    userGraph.getCurrentUser()->posts.push(content);
                    cout << "\nPost added successfully.\n";
                }
                else
                {
                    cout << "\nPlease login first.\n";
                }
                break;

            case '5':
                userGraph.displayFollowerPosts();
                break;

            case '6':
                cout << "\nEnter recipient's username: ";
                cin >> recipient;
                cout << "Enter message: ";
                cin.ignore();
                getline(cin, message);

                recipientUser = userGraph.searchUser(recipient);

                if (recipientUser)
                {
                    recipientUser->messages.push(userGraph.getCurrentUser()->name, message);
                    cout << "\nMessage sent successfully.\n";
                }
                else
                {
                    cout << "\nRecipient not found.\n";
                }
                break;

            case '7':
                cout << "\nEnter the username of the person whose messages you want to view: ";
                cin >> recipient;
                userGraph.getCurrentUser()->messages.display(userGraph.getCurrentUser()->name, recipient);
                break;

            case '8':
                userGraph.getCurrentUser()->friendRequests.display();
                break;

            case '9':
                userGraph.getCurrentUser()->notifications.display();
                break;

            case 'A':
                userGraph.displayFriends(userGraph.getCurrentUser()->name);
                break;

            case 'B':
                userGraph.getCurrentUser()->posts.display();
                break;

            case 'C':
                cout << "\nEnter username to search: ";
                cin >> name;
                userGraph.searchUser(name);
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
                break;
            }
        }
    }
    return 0;
}
