# Baby Sleep Mode (C Project)

A simple C console application that simulates a “Baby Sleep Mode.”  
When activated, the program sends a predefined message to all saved contacts,  
mimicking how a phone might automatically notify people while the baby is sleeping.

## 📌 Features
- Add new contacts (name + phone number)
- List all saved contacts
- Define a custom message template
- Activate **Baby Sleep Mode** to “send” the message to all contacts
- Simple, clean C console structure using:
  - `struct`
  - arrays
  - functions
  - basic file simulation (RAM-based for now)


## 🧠 Purpose of This Project
This project is inspired by a real-life scenario:

> While trying to put a baby to sleep, phone calls can wake the baby.  
> Parents often want a mode where calls do not ring and the caller automatically receives a message like:  
> **“The baby is sleeping. I’ll call back later.”**

Since actual phones don’t provide this feature,  
this project demonstrates how such a system could be simulated logically in C.


## 🛠️ Technologies Used
- **C Programming Language**
- Console input/output
- `struct` based data storage
- Custom functions for each feature
- Simple in-memory “database”


## 📂 Project Structure
main.c          --> main program logic  
contacts[]      --> stored in memory  
message[]       --> custom message template  

▶️ How to Run
Open the project in VS Code, Dev-C++, or any C compiler
Compile:
gcc main.c -o baby
Run:
./baby

📸 Example Output
1. Add Contact  
2. List Contacts  
3. Update Message  
4. Activate Baby Sleep Mode  
5. Exit
Enter choice: 4
Sending message to:
- Alice (0555...) : The baby is sleeping. I’ll call back later.
- Bob (0532...) : The baby is sleeping. I’ll call back later.

  
🎯 Future Improvements (Optional)
These are optional ideas if you ever revisit the project:
File saving (contacts.txt, message.txt)
Multiple message templates
“Quiet hours” scheduling
Real SMS integration using APIs (Twilio, Vonage, etc.)
GUI version (C# WinForms)
