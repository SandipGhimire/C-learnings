## LEVEL 1: WHAT IS WHAT? (Understanding Data Types & Structures)

### 1. **What is a String?**

```
string qn;
```

**In Simple Terms:** A string is like a container that holds text (words, sentences, characters, numbers written as text).

**Real-World Example:**
- `"Capital of Nepal?"` ← This is a STRING
- `"Kathmandu"` ← This is also a STRING
- `"Hello World"` ← STRING

**Key Points:**
- Strings are enclosed in double quotes: `"like this"`
- They can contain letters, numbers, symbols, and spaces
- They are like a chain of characters linked together
- In this code, we use `string` from the `<string>` library

**Why use strings?**
- To store questions
- To store answer options
- To store any text-based information


### 2. **What is an Array?**

```
array<string, 4> answers;
```

**In Simple Terms:** An array is like a shelf with a fixed number of boxes. Each box holds something, and you access it by its position.

**Real-World Example:**
```
If we have: array<string, 4> answers;

Position:    [0]              [1]            [2]           [3]
Content:   "A. London"  "B. Berlin"  "C. Kathmandu"  "D. Rome"
           └─────────────────────────────────────────────────┘
                         This is the ARRAY
```

**Breaking Down `array<string, 4>`:**
- `array` = "This is an array" (a container with fixed size)
- `<string, 4>` = "It holds STRING values, and has exactly 4 slots"
- `string` = Each position stores TEXT (a string)
- `4` = There are exactly 4 positions (0, 1, 2, 3)

**Key Points:**
- Arrays have FIXED size (can't change the number of boxes)
- Each position is numbered starting from 0 (not 1!)
- Position 0 = first item
- Position 1 = second item
- Position 2 = third item
- Position 3 = fourth item
- You access items using square brackets: `answers[0]`, `answers[1]`, etc.

**Why use arrays?**
- Perfect for storing multiple answers (always 4 options: A, B, C, D)
- You know exactly how many slots you need
- Easy to loop through and display all answers


### 3. **What is a Vector?**

```
vector<QuizItem> quiz;
```

**In Simple Terms:** A vector is like a magic shelf that CAN GROW or SHRINK. You can add more boxes or remove boxes as needed.

**Real-World Example:**
```
Start with 1 question:
[Question 1]

Add another:
[Question 1] [Question 2]

Add another:
[Question 1] [Question 2] [Question 3]

The shelf GROWS as you need more space!
```

**Breaking Down `vector<QuizItem>`:**
- `vector` = "This is a vector" (a container that can change size)
- `<QuizItem>` = "It holds QuizItem objects"
- `QuizItem` = A custom type (we'll explain this next!)

**Key Points:**
- Vectors can grow or shrink (flexible!)
- They start empty and you can add items
- You can also access them with square brackets like arrays
- You can use `.size()` to find how many items are in it

**Difference: Array vs Vector**
```
ARRAY:              VECTOR:
Fixed size (4)      Can grow (10, 100, 1000...)
Can't add more      Can add/remove items
Use when you        Use when you don't
know exact count    know exact count
```

**Why use vectors?**
- We might have 10 quiz questions now, but 20 later
- We don't need to know the number of questions beforehand
- We can add more questions easily


### 4. **What is a Struct?**

```
struct QuizItem {
    string qn;
    array<string, 4> answers;
    char answer;
};
```

**In Simple Terms:** A struct is like a custom blueprint or template that groups related information together.

**Real-World Example - Without Struct (Wrong Way):**
```
string question = "Capital of Nepal?";
array<string, 4> ansOptions = {"A. London", "B. Berlin", "C. Kathmandu", "D. Rome"};
char correctAnswer = 'C';
// These are separate, no connection!
```

**Better Way - With Struct:**
```
struct QuizItem {
    string qn;                    // Question
    array<string, 4> answers;     // 4 Answer choices
    char answer;                  // Correct answer
};
// All related! One complete question unit
```

**Breaking Down the Struct:**
```
struct QuizItem {          // "Create a new type called QuizItem"
    string qn;             // It contains a STRING for question
    array<string, 4> answers;  // It contains an ARRAY of 4 strings for options
    char answer;           // It contains a CHAR for the correct answer
};                         // End of definition
```

**What is a `char`?**
- `char` = a single character (one letter)
- Examples: `'A'`, `'B'`, `'C'`, `'D'`, `'X'`
- Note: Single quotes (not double quotes!)
- Perfect for storing single answer choices

**Why use structs?**
- Keep related data together
- Make code organized and readable
- Reuse the same structure for all questions
- It's like creating your own data type!

**How it works:**
```
BEFORE: Three separate pieces of information
   Question:  "Capital of Nepal?"
   Answers:   ["A. London", "B. Berlin", "C. Kathmandu", "D. Rome"]
   Answer:    'C'

AFTER: One QuizItem that contains all three
   QuizItem {
       qn: "Capital of Nepal?"
       answers: ["A. London", "B. Berlin", "C. Kathmandu", "D. Rome"]
       answer: 'C'
   }
```


### 5. **What are the Headers/Libraries?**

```cpp
#include <iostream>    // Input/Output (cout, cin)
#include <vector>      // Vector data structure
#include <array>       // Array data structure
#include <string>      // String data type
```

**In Simple Terms:** These are toolkits you're importing from C++'s library.

| Header | What It Gives You | Used For |
|--------|------------------|----------|
| `<iostream>` | `cout` (output) and `cin` (input) | Printing text and reading user input |
| `<vector>` | `vector<>` type | Creating flexible lists |
| `<array>` | `array<>` type | Creating fixed-size lists |
| `<string>` | `string` type | Working with text |

**Think of it like:**
- `#include` = "I want to use..."
- `<iostream>` = "...the printing/reading tools"

---

## LEVEL 2: WHAT DOES WHAT? (Line-by-Line Breakdown)

### **Top Section: Includes and Setup**

```cpp
#include <iostream>
```
**What it does:** Imports the input/output library so we can use `cout` (to print) and `cin` (to receive user input)

```cpp
#include <vector>
#include <array>
#include <string>
```
**What they do:** Import the vector, array, and string data types so we can use them in our code

```cpp
using namespace std;
```
**What it does:** This lets us write `cout` instead of `std::cout`, and `vector` instead of `std::vector`. It's a shortcut to save typing. (Think of it as saying "assume I mean standard library")


### **The Struct Definition**

```cpp
struct QuizItem {
```
**What it does:** Creates a new data type called `QuizItem`. From now on, we can create `QuizItem` objects.

```cpp
    string qn;
    array<string, 4> answers;
    char answer;
```
**What they do:** Define what information each QuizItem contains:
- `qn` = the question text
- `answers` = 4 answer options
- `answer` = which letter (A, B, C, or D) is correct

```cpp
};
```
**What it does:** End the struct definition


### **Creating the Quiz Data**

```cpp
vector<QuizItem> quiz = {
```
**What it does:** Creates a vector (list) called `quiz` that will hold QuizItem objects. The `= {` starts filling it with data.

```cpp
    {
        "Capital of Nepal?",
        {
            "A. London",
            "B. Berlin",
            "C. Kathmandu",
            "D. Rome",
        },
        'C'
    },
```
**What it does:** Creates the FIRST QuizItem with:
- Question: `"Capital of Nepal?"`
- Four answers (in an array): `{"A. London", "B. Berlin", "C. Kathmandu", "D. Rome"}`
- Correct answer: `'C'` (Kathmandu)

**Note:** The curly braces `{}` are used to create each QuizItem following the struct structure

```cpp
    // ... more quiz items ...
};
```
**What it does:** The semicolon `;` ends the quiz vector definition. All 10 questions are now stored.


### **The runQuiz() Function**

```cpp
int runQuiz()
{
```
**What it does:** Creates a function called `runQuiz()` that:
- Does NOT take any input parameters (empty parentheses)
- Returns an `int` (integer) - the score

```cpp
    int score = 0;
    char input;
```
**What they do:**
- `int score = 0;` = Create a variable called `score` and set it to 0
- `char input;` = Create a variable to store the user's answer (A, B, C, or D)

```cpp
    for (int i = 0; i < quiz.size(); i++) {
```
**What it does:** Start a LOOP that goes through each question:
- `int i = 0` = Start counting from 0
- `i < quiz.size()` = Keep going while `i` is less than the number of questions (10)
- `i++` = Add 1 to `i` each time (0, 1, 2, 3, ... 9)

**In other words:** "Do this 10 times, once for each question"

```cpp
        cout << "\n" << quiz[i].qn << endl;
```
**What it does:** Print the question:
- `"\n"` = New line (blank line for spacing)
- `quiz[i]` = Access the i-th question (0, 1, 2, ...)
- `.qn` = Access the question text field
- `endl` = New line after the question

**Example output:**
```
Capital of Nepal?
```

```cpp
        for (int j = 0; j < quiz[i].answers.size(); j++) {
            cout << quiz[i].answers[j] << endl;
        }
```
**What it does:** INNER LOOP - Print all 4 answer options:
- `int j = 0; j < 4; j++` = Loop 4 times (for positions 0, 1, 2, 3)
- `quiz[i].answers[j]` = Access answer at position j
- Print each one on a new line

**Example output:**
```
A. London
B. Berlin
C. Kathmandu
D. Rome
```

```cpp
        cout << "Answers: ";
        cin >> input;
```
**What they do:**
- First line: Print "Answers: " (asking the user to enter their choice)
- Second line: Wait for user to type a character and store it in `input`

**What the user sees and does:**
```
Answers: [user types: A, B, C, or D here]
```

```cpp
        input = toupper(input);
```
**What it does:** Convert the input to UPPERCASE
- If user types `'a'`, it becomes `'A'`
- If user types `'C'`, it stays `'C'`
- This makes sure we match the correct answer format

```cpp
        if(input == quiz[i].answer) score++;
```
**What it does:** Check if the answer is correct:
- `input == quiz[i].answer` = Does the user's answer match the correct answer?
- If YES: `score++` = Add 1 to the score
- If NO: Do nothing, move to next question

```cpp
    }
    return score;
}
```
**What they do:**
- `}` = End of the for loop
- `return score;` = Send the final score back to whoever called this function
- `}` = End of the runQuiz() function


### **The main() Function**

```cpp
int main() {
```
**What it does:** This is the starting point of the program. Everything here runs first.

```cpp
    cout << "=== Welcome to Quiz ===";
```
**What it does:** Print a welcome message to the screen

**Output:**
```
=== Welcome to Quiz ===
```

```cpp
    int score = runQuiz();
```
**What it does:** 
- Call the `runQuiz()` function (which runs all 10 questions)
- Store whatever score it returns in a variable called `score`
- The user goes through the whole quiz here!

```cpp
    cout << "\nScore: " << score << "/" << quiz.size() << endl;
```
**What it does:** Print the final score:
- `"\n"` = New line
- `"Score: "` = Print the text "Score: "
- `score` = Print the number of correct answers
- `"/"` = Print a slash
- `quiz.size()` = Print the total number of questions (10)
- `endl` = New line

**Example output:**
```
Score: 7/10
```

```cpp
    return 0;
}
```
**What it does:** 
- `return 0;` = Tell the computer "The program finished successfully"
- `}` = End of the main() function (and the whole program)

---

## LEVEL 3: WHAT IS THE FOLLOWING TOOL AND HOW DOES IT USE THE "WHAT"?

### **Tool 1: Vector**

**What is it?**
A vector is a dynamic list container that can grow or shrink.

**How does it use the "what" (our data)?**

```cpp
vector<QuizItem> quiz;
```

1. **STORAGE:** Holds multiple QuizItem objects
   ```
   Position 0: QuizItem{qn: "Capital of Nepal?", answers: [...], answer: 'C'}
   Position 1: QuizItem{qn: "Highest mountain?", answers: [...], answer: 'B'}
   Position 2: QuizItem{qn: "National animal?", answers: [...], answer: 'B'}
   ... (10 questions total)
   ```

2. **ACCESSING:** Get items using index
   ```cpp
   quiz[0]    // Get first question
   quiz[5]    // Get sixth question
   quiz[9]    // Get last question
   ```

3. **SIZING:** Find how many items
   ```cpp
   quiz.size()    // Returns 10 (we have 10 questions)
   ```

4. **USAGE IN CODE:**
   ```cpp
   for (int i = 0; i < quiz.size(); i++) {
       quiz[i]    // Access each question one by one
   }
   ```

**Why use vector here instead of array?**
- We can easily add more questions later
- Array requires fixed size at creation


### **Tool 2: Array**

**What is it?**
An array is a fixed-size container with a predetermined number of slots.

**How does it use the "what" (our data)?**

```cpp
array<string, 4> answers;
```

1. **STORAGE:** Holds exactly 4 answer strings
   ```
   Position 0: "A. London"
   Position 1: "B. Berlin"
   Position 2: "C. Kathmandu"
   Position 3: "D. Rome"
   ```

2. **ACCESSING:** Get each answer option
   ```cpp
   answers[0]    // "A. London"
   answers[1]    // "B. Berlin"
   answers[2]    // "C. Kathmandu"
   answers[3]    // "D. Rome"
   ```

3. **LOOPING:** Display all options
   ```cpp
   for (int j = 0; j < quiz[i].answers.size(); j++) {
       cout << quiz[i].answers[j];    // Print each answer
   }
   ```

**Why use array here instead of vector?**
- Quiz questions ALWAYS have exactly 4 options
- No need for flexibility
- Faster and more memory-efficient for fixed size


### **Tool 3: String**

**What is it?**
A text container that holds sequences of characters.

**How does it use the "what" (our data)?**

```cpp
string qn;    // Question text
```

1. **STORAGE:** Holds the question text
   ```cpp
   "Capital of Nepal?"
   "Highest mountain in the world located in Nepal?"
   "National animal of Nepal?"
   ```

2. **PRINTING:** Display the question
   ```cpp
   cout << quiz[i].qn;    // Print the question string
   ```

3. **FLEXIBILITY:** Strings can be any length
   ```cpp
   "Capital?" (short)
   "Which mountain is the tallest and most famous..." (long)
   // Both work fine!
   ```

**Why use string?**
- Questions vary in length
- Easy to read and manipulate text
- Built-in support for input/output


### **Tool 4: Struct**

**What is it?**
A custom data type that groups related information together.

**How does it use the "what" (our data)?**

```cpp
struct QuizItem {
    string qn;
    array<string, 4> answers;
    char answer;
};
```

1. **ORGANIZATION:** Groups question components
   ```
   One QuizItem = (question + answers + correct_answer)
   Instead of: (question) + (answers) + (correct_answer) scattered
   ```

2. **CREATING OBJECTS:** Make quiz items easily
   ```cpp
   QuizItem item1 = {
       "Capital of Nepal?",
       {"A. London", "B. Berlin", "C. Kathmandu", "D. Rome"},
       'C'
   };
   // Now all related data is in ONE object
   ```

3. **ACCESSING FIELDS:** Get specific information
   ```cpp
   item1.qn        // Get the question
   item1.answers   // Get the answers array
   item1.answer    // Get the correct answer
   ```

4. **STORING IN VECTOR:** All items together
   ```cpp
   vector<QuizItem> quiz;
   // One vector holds multiple complete quiz questions
   ```

**Why use struct?**
- Keeps related data together
- Makes code cleaner and more logical
- Easy to add, remove, or modify questions
- Professional data organization


### **How They All Work Together**

```
HIERARCHY:

vector<QuizItem>
    │
    ├─ QuizItem #1
    │   ├─ string qn: "Capital of Nepal?"
    │   ├─ array<string, 4> answers: ["A. London", "B. Berlin", "C. Kathmandu", "D. Rome"]
    │   └─ char answer: 'C'
    │
    ├─ QuizItem #2
    │   ├─ string qn: "Highest mountain?"
    │   ├─ array<string, 4> answers: ["A. K2", "B. Mount Everest", "C. Kanchenjunga", "D. Lhotse"]
    │   └─ char answer: 'B'
    │
    └─ ... (10 total)
```

**Data Flow in the Program:**

```
START
  │
  ├─ Vector contains 10 QuizItems
  │
  ├─ runQuiz() loops through vector
  │   │
  │   ├─ For each QuizItem:
  │   │   ├─ Print the string (question)
  │   │   ├─ Loop through the array (4 answers)
  │   │   ├─ Get user input
  │   │   ├─ Compare with char (correct answer)
  │   │   └─ Increment score if correct
  │   │
  │   └─ Return final score
  │
  └─ Print score to user
```

---

## SUMMARY TABLE

| Component | Type | Purpose | Details |
|-----------|------|---------|---------|
| `quiz` | `vector<QuizItem>` | Hold all questions | Flexible, can grow |
| `qn` | `string` | Store question text | Any length |
| `answers` | `array<string, 4>` | Store 4 options | Fixed size of 4 |
| `answer` | `char` | Store correct answer | Single character (A/B/C/D) |
| `score` | `int` | Count correct answers | Integer number |
| `input` | `char` | Store user's choice | Single character |

---

## Quick Reference Example

```cpp
// Creating ONE complete quiz item
QuizItem item = {
    "Capital of Nepal?",                    // STRING - the question
    {                                        // ARRAY - the 4 options
        "A. London",
        "B. Berlin",
        "C. Kathmandu",
        "D. Rome"
    },
    'C'                                      // CHAR - correct answer
};

// Adding to VECTOR
vector<QuizItem> myQuiz;
myQuiz.push_back(item);    // Add item to vector

// Accessing
myQuiz[0].qn              // "Capital of Nepal?"
myQuiz[0].answers[2]      // "C. Kathmandu"
myQuiz[0].answer          // 'C'
```

---

## Key Takeaways for Beginners

1. **String** = Text container (flexible length)
2. **Array** = Fixed-size list (always same number of items)
3. **Vector** = Flexible list (can grow/shrink)
4. **Struct** = Custom grouping of related data
5. **Char** = Single character (one letter/symbol)
6. **Int** = Whole number (1, 2, 3, not 1.5)

These work together to create a well-organized, efficient quiz program!