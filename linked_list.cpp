#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long int
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define INF (ll)1e18
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;
class linked_list {
public:
    ll data;
    linked_list *next;
    linked_list() {
        this->next = NULL;
    }
    linked_list(ll data) {
        this->data = data;
        this->next = NULL;
    }
    linked_list* add(ll data, linked_list *head) {
        //Case 1
        if (head == NULL) {
            linked_list *temp = new linked_list(data);
            head = temp;
        } else {
            linked_list *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new linked_list(data);
        }
        return head;
    }
    void print(linked_list *head) {
        auto temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        } cout << endl;
    }
    ll middle_element(linked_list *head) {
        auto sp = head, fp = head;
        while (fp != NULL and fp->next != NULL) {
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp->data;
    }
    linked_list *delete_middle(linked_list *head) {
        auto sp = head, fp = head;
        auto pre = sp;
        while (fp != NULL and fp->next != NULL) {
            pre = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        pre->next = sp->next;
        delete sp;
        return head;
    }
    linked_list *delete_linked_list(linked_list* head) {
        linked_list* pre = head;
        head = head->next;
        if (head == NULL) delete pre;
        while (head != NULL) {
            delete pre;
            pre = head;
            head = head->next;
        }
        return head;
    }
    void print_reverse(linked_list* head) {
        if (head == NULL) return;
        print_reverse(head->next);
        cout << head->data << " ";
    }
    linked_list *reverse_linked_list(linked_list *head) {
        linked_list *cur = head, *next = head, *prev = NULL;
        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool is_palindrome(linked_list* &left, linked_list* right) {
        if (right == NULL) return true;
        bool first = is_palindrome(left, right->next);
        if (first == false) return false;
        bool second = (right->data == left->data);
        left = left->next;
        return second;
    }
    linked_list* remove_duplicate_sorted(linked_list* head) {
        linked_list* cur = head;
        while (cur->next != NULL) {
            if (cur->data == cur->next->data) {
                auto temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else cur = cur->next;
        }
        return head;
    }
    linked_list *remove_duplicate_unsorted(linked_list* head) {
        set<ll> vis; linked_list* cur = head; linked_list* pre = head;
        while (cur) {
            if (vis.count(cur->data)) {
                pre->next = cur->next;
                delete cur;
            } else {
                vis.insert(cur->data);
                pre = cur;
            }
            cur = pre->next;
        }
        return head;
    }
    bool detect_loop(linked_list* head) {
        auto sp = head, fp = head;
        while (fp and fp->next) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp) return true;
        } return false;
    }
    linked_list* remove_loop(linked_list* head) {
        auto sp = head, fp = head;
        while (fp and fp->next) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp)
                break;
        }
        if (sp == fp) {
            sp = head;
            while (sp->next != fp->next) {
                sp = sp->next; fp = fp->next;
            }
            fp->next = NULL;
        }
        return head;
    }
    ll intersection_point(linked_list* head1, linked_list* head2) {
        auto cur1 = head1, cur2 = head2;
        while (cur1 != cur2) {
            if (cur1 == NULL) cur1 = head2;
            else cur1 = cur1->next;
            if (cur2 == NULL) cur2 = head1;
            else cur2 = cur2->next;
        }
        return cur1->data;
    }
    linked_list* odd_even(linked_list* head) {
        auto o = head, e = head->next, temp = e;
        while (e != NULL && e->next != NULL) {
            o->next = e->next;
            o = o->next;
            e->next = o->next;
            e = e->next;
        }
        o->next = temp;
        return head;
    }
    linked_list* merge(linked_list* h1, linked_list* h2) {
        if (h1 == NULL or h2 == NULL)
            return (h1 == NULL) ? h2 : h1;
        if (h1->data < h2->data) {
            h1->next = merge(h1->next, h2);
            return h1;
        } else
        {
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }
    linked_list* merge_sort(linked_list* head) {
        if (head == NULL or head->next == NULL) return head;
        auto sp = head, fp = head, pre = sp;
        while (fp and fp->next) {
            pre = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        pre->next = NULL;
        auto h1 = merge_sort(head);
        auto h2 = merge_sort(sp);
        return merge(h1, h2);
    }
};
int main() {
    fast_io;
    linked_list *head = NULL;
    head = head->add(1, head);
    head = head->add(2, head);
    head = head->add(6, head);
    head = head->add(4, head);
    head = head->add(3, head);
    head = head->add(5, head);

    // head->print(head); cout << endl;
    // cout << head->middle_element(head) << endl;
    // head = head->add(8, head);
    // cout << head->middle_element(head) << endl;
    // head = head->delete_middle(head);
    // head->print(head);
    // //Delete full linked list
    // head = head->delete_linked_list(head);
    // if (head != NULL)
    //  head->print(head);
    // else cout << "list is empty";
    // head->print_reverse(head);
    //reverse the linked list
    // head = head->reverse_linked_list(head);
    // head->print(head);
    //Recursion Palindrome
    // cout << head->is_palindrome(head, head);
    //Delete duplicates from lilnked list in sorted list
    // head = head->remove_duplicate_sorted(head);
    // head = head->remove_duplicate_unsorted(head);
    // head->print(head);
    // Detect Loop
    // auto cur = head, temp = head;
    // while (cur->next) {
    //  cur = cur->next;
    // } while (temp->data != 2)
    //  temp = temp->next;
    // cur->next = temp;
    // cout << head->detect_loop(head);
    // head = head->remove_loop(head);
    // cout << head->detect_loop(head);
    //INtersection POint of two linked list

    // linked_list *head1 = NULL, *head2 = NULL;
    // //Linked list 1
    // head1 = head1->add(1, head1);
    // head1 = head1->add(2, head1);
    // head1 = head1->add(3, head1);
    // head1 = head1->add(4, head1);
    // head1 = head1->add(5, head1);
    // //Linked list 2
    // head2 = head2->add(8, head2);
    // head2 = head2->add(6, head2);
    // auto cur = head2, temp = head1;
    // while (cur->next != NULL)
    //  cur = cur->next;
    // while (temp->data != 4)
    //  temp = temp->next;
    // cur->next = temp;
    // cout << head1->intersection_point(head1, head2) << endl;
//Odd Even Linked List
    // head = head->odd_even(head);
    // head->print(head);
//Merged Sort on linked list
    head = head->merge_sort(head);
    head->print(head);
}
