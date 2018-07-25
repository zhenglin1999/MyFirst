//使用堆的方法，实乃前所未见。。。
class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newHead = nullptr;
        ListNode* newEnd = nullptr;
        
        auto compareNodes = [](ListNode* a, ListNode* b) {
            if (a == nullptr) return false;
            else if (b == nullptr) return true;
            return a->val > b->val;
        };
        
        make_heap(lists.begin(), lists.end(), compareNodes);
        
        while (!lists.empty()) {
            pop_heap(lists.begin(), lists.end(), compareNodes);
            if (lists.back() == nullptr) {
                lists.pop_back();
                continue;
            }
            if (newHead == nullptr) {
                newHead = lists.back();
                newEnd = lists.back();
            } else {
                newEnd->next = lists.back();
                newEnd = newEnd->next;
            }
            if (lists.back()->next == nullptr) {
                lists.pop_back();
            } else {
                lists[lists.size() - 1] = lists.back()->next;
                push_heap(lists.begin(), lists.end(), compareNodes);
            }
        }
        return newHead;
    }
};
