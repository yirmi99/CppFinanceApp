# **Personal Finance Tracker**  

## **Overview**  
CppFinanceApp is a simple app for managing personal finances. It lets you add transactions, check exchange rates, and back up data online. The app has a user friendly interface built with ImGui and runs smoothly with multithreading.  

## **Features**  
- Add, edit, and delete transactions  
- Categorize expenses  
- View transaction history in a clean UI  
- Fetch live exchange rates  
- Auto backup transactions to JSONBin  
- Restore transactions when needed  
- Runs efficiently using background threads  

## **Setup**  

### **1. Clone the project**  
```sh
git clone --recursive https://github.com/your-username/CppFinanceApp.git
cd CppFinanceApp
```

### **2. Install dependencies (Mac)**  
```sh
brew install cmake openssl
```

### **3. Build & run**  
```sh
rm -rf build/                      
cmake -B build                     
cmake --build build                 
./build/CppFinanceApp               
```
