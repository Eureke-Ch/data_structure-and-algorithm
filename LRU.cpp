#include <unordered_map>
using namespace std;
class Double_list{
    public:
        int key, value;
        Double_list* next;
        Double_list* pre;
        Double_list():key(0),value(0),next(nullptr),pre(nullptr){};
        Double_list(int x, int y):key(x),value(y),next(nullptr),pre(nullptr){};
};
class LRUCache {
public:
    Double_list lru;
    unordered_map<int, Double_list*> rec;
    int cur_size;
    int cap;
    Double_list* head;
    Double_list* tail;
    LRUCache(int capacity) {
        cap = capacity;
        cur_size = 0;
        head = new Double_list(-1, -1);
        tail = new Double_list(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(rec.find(key) != rec.end()){
            int value = rec[key]->value;
            rec[key]->pre->next = rec[key]->next;
            rec[key]->next->pre = rec[key]->pre;

            head->next->pre = rec[key];
            rec[key]->next = head->next;
            head->next = rec[key];
            rec[key]->pre = head;

            rec[key] = head->next;
            return value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(rec.find(key) != rec.end()){
            rec[key]->pre->next = rec[key]->next;
            rec[key]->next->pre = rec[key]->pre;

            rec[key]->value = value;
            head->next->pre = rec[key];
            rec[key]->next = head->next;
            head->next = rec[key];
            rec[key]->pre = head;

            rec[key] = head->next;
            return ;
        }else{
            if(cur_size >= cap){
                Double_list* temp = tail->pre;
                temp->pre->next = tail;
                tail->pre = temp->pre;
                rec.erase(temp->key);

                temp->key = key;
                temp->value = value;
                head->next->pre = temp;
                temp->next = head->next;
                head->next = temp;
                temp->pre = head;

                rec[key] = head->next;
            }else{
                Double_list* temp = new Double_list(key, value);

                head->next->pre = temp;
                temp->next = head->next;
                head->next = temp;
                temp->pre = head;

                rec[key] = head->next;
                cur_size++;
            }
        }
        return ;
    }
};
