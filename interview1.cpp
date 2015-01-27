Node* doMerge(Node *firstHead, Node *secondHead)
{
    Node *traverse1 = firstHead;
    Node *traverse2 = secondHead;
    Node *prev1 = NULL;

    while (!((traverse1==NULL) && (traverse2 == NULL)))
    {
        if (traverse2 == NULL) break; //already reached the last pointer of second linked list
        if (traverse1 == NULL) //already reached the last pointer of first linked list
        {
            prev1->next = traverse2;
            break;
        }
        
        if (traverse1->data < traverse2->data)
        {
            prev1 = traverse1;
            traverse1 = traverse1->next;
        }
        else
            if (traverse2->data <= traverse1->data)
            {
                Node *temp = traverse2->next;
                if (prev1 = NULL)
                {
                    traverse2->next = traverse1;
                    firstHead = traverse2;
                    prev1 = traverse2;
                    traverse2 = temp;
                }
                else
                {
                    prev1->next = traverse2;
                    traverse2->next = traverse1;
                    traverse2 = temp;
                    prev1 = traverse1;
                }
            }
    }

    return firstHead;
}


Node* merge(int lower, int upper)
{
    if (lower == upper) return linkedLists[lower];
    if (lower == upper-1) return doMerge(linkedLists[lower], linkedLists[upper]);
    
    int mid = (lower+upper)/2;
    return doMerge(merge(lower, mid), merge(mid+1, upper));
    
}

//if there is k linked list
Node *mergedHead = merge(0, k-1);

// Array of Contact
// [0] Adhit: a@b.c, d@e.f
// [1] Rei: a@b.c, m@n.o
// [2] Hendi: g@h.i
// [3] Reinardus: d@e.f, j@k.l

// Array of DedupedContact
// [0] Name: {Adhit, Reinardus, Rei}
// [1] Name: {Hendi}

// [0] Adhit
// emailMap[a@b.c] = 0
// emailMap[d@e.f] = 0

// [2] Reinardus
// emailMap[d@e.f] ==> already registered
// Unite(0,2)

// parent ==>store all parents in the UFDS
// [0] = 0
// [1] = 0
// [2] = 2
// [3] = 0