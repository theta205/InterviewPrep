struct Node{
    int val;
    int key;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class LRUCache {
public:
    
    unordered_map<int,Node*> dict;
    int size;
    int curr_size;
    Node* last = nullptr;
    Node* first = nullptr;
    
    LRUCache(int capacity) {
        size = capacity;
        curr_size = 0;
    }
    
    int get(int key) {
        if(dict[key] != nullptr){
            Node* curr = dict[key];
            
            if (last != curr){
                if(first == curr){ // remove curr from beggin of cache
                    first = first -> next;
                    first -> prev = nullptr;

                }else{
                    curr -> prev -> next = curr -> next; // elim curr from middle of cache;
                    curr -> next -> prev = curr -> prev;
                }
                
                last -> next = curr; // add curr to end of cache;
                curr -> prev = last;
                last = curr;
            }
            return dict[key] -> val; // return value
        }
        else{
            return -1; // if key doesn't exist return -1
        }
    }
    
    void put(int key, int value) {

        if (dict[key] != nullptr) { // if key exist in cache currently 
            dict[key] -> val = value; // update value
            this -> get(key); // call this to update order
            return;
        }

        // Create new node
        Node* node = new Node();
        node -> val = value;
        node -> key = key;
        dict[key] = node; 
        
        if(curr_size < size){ // Have not filled cache yet
            if (curr_size == 0){ // If first input in cache
                first = node;
            }
            else{ // If not first input in cache
                last -> next = node;
                node -> prev = last;
            }
            last = node; 
            last -> next = nullptr;
            curr_size++;
        }
        else{ // cache is filled
            dict[first -> key] = nullptr; // remove oldest used 

            if (first != last) { // if more than one in cache
                first = first -> next;
                first -> prev = nullptr;
                last -> next = node;
                node -> prev = last;
                last = node;
            }
            else{ // if only one in cache
                first = node;
                last = node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
