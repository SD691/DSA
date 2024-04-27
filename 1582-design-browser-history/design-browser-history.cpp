class BrowserHistory {
public:

    class node{
        public:
        node* next;
        node* prev;
        string val;
        node(){
            next = NULL;
            prev = NULL;
            val = "";
        }
        node(string v){
            val = v;
            next = NULL;
            prev= NULL;
        }
    };

    node* head = NULL;
    node* home = NULL;
    BrowserHistory(string homepage) {
        home = new node(homepage);
        head = home;
    }
    
    void visit(string url) {
        node* visit_node = new node(url);
        home->next = visit_node;
        visit_node->prev = home;
        home = visit_node;
    }
    
    string back(int steps) {
        string ans;
        while(home->prev!=NULL &&  steps>0){
            home=home->prev; 
            steps--;
        }

            return home->val;

    }
    
    string forward(int steps) {
        string ans;
        while(home->next!=NULL && steps>0){
            home = home->next;
            steps--;
        }
        return home->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */