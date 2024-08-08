#include <stdio.h>
#include <iterator>
#include <bits/stl_algo.h>
// #include <algorithm>
int main(){
    int a[3];
    char c;
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    // std::sort(a,a+3);
    
      __glibcxx_function_requires(_Mutable_RandomAccessIteratorConcept<
	    _RandomAccessIterator>)
      __glibcxx_function_requires(_LessThanComparableConcept<
	    typename iterator_traits<_RandomAccessIterator>::value_type>)
      __glibcxx_requires_valid_range(a, a+3);
      __glibcxx_requires_irreflexive(a, a+3);

      std::__sort(a, a+3, __gnu_cxx::__ops::_Iter_less_iter());
    scanf("%c",&c);
    
        scanf("%c",&c);
        printf("%d ",a[c-'A']);
        
        scanf("%c",&c);
        printf("%d ",a[c-'A']);
        
        scanf("%c",&c);
        printf("%d",a[c-'A']);
}
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main(){
//     int a[3];
//     char c;
//     scanf("%d%d%d",&a[0],&a[1],&a[2]);
//     sort(a,a+3);
//     for(int i = 1; i <= 3;i++){
//         cin >> c;
//         printf("%d",a[c-'A']);
//     }
// }