#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List Tbl, ElementType K );

int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);

    return 0;
}
Position BinarySearch( List Tbl, ElementType K ) {
    Position low = 0, high = Tbl->Last;
    while(low <= high) {
        Position mid = (low+high)/2;
        if(Tbl->Data[mid] == K) {
            return mid;
        }
        else if(Tbl->Data[mid] > K) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return NotFound;
}
