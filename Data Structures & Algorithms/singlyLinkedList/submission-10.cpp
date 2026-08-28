class ListNode{
public:
    int value;
    ListNode* next;

    ListNode(int value){
        this->value = value;
        this->next = nullptr;
    }

};


class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int index) {
        ListNode* curr = head;
        int i = 0;
        while (curr != nullptr){
            if (i == index){
                return curr->value;
            }
            i++;
            curr = curr->next;
        }

        return -1;
    }

    void insertHead(int val) {
        ListNode* insertion = new ListNode(val);

        
        insertion->next = head;
        head = insertion;
        
        if (tail == nullptr) {
            tail = insertion;
        }


    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);

         if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    bool remove(int index) {
       int i = 0;
        ListNode* curr = head;
        if (head == nullptr || index < 0) return false;
        if (index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr; // List is now completely empty
            }
            delete toDelete;
            return true;
        }
        while (i < index - 1 && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        // Remove the node ahead of curr
        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;

        ListNode *curr = head;
        while (curr != nullptr){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};
