class Solution {
  public:
   string res="";
   stack<char> app;
   stack<char> Undo;
  
    void append(char x) {
        // append x into document
        app.push(x);
        res+=x;
        
    }

    void undo() {
        // undo last change
        res.pop_back();
        char z=app.top();
        app.pop();
        Undo.push(z);
    }

    void redo() {
        // redo changes
        char ch=Undo.top();
        Undo.pop();
        res+=ch;
        app.push(ch);
    }

    string read() {
        // read the document
        return res;
    }
};