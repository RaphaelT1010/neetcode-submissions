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
        this->head = new ListNode(-1);
        this->tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
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

        
        insertion->next = head->next;
        head->next = insertion;
        
        if (insertion->next == nullptr){
            tail = insertion;
        }


    }
    
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
       int i = 0;
        ListNode* curr = head;
        while (i < index && curr != nullptr) {
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

        ListNode *curr = head ->next;
        while (curr != nullptr){
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};
