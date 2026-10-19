// Example assignment

#include <string>
#include "code.hpp"

int sumOfList(ListInterface<int>& aList){
    // traverse the list and add the values
    int sum = 0;
    for (int i = 0; i < aList.getLength(); i++){
        sum += aList.getEntry(i + 1);
    }
    return sum;
}

/** @brief: swap values at locations i and j.
 * @pre: 1 <= i <= aList.getLength() and 1 <= j <= aList.getLength()
 * @return: true if successfully swapped, false if not.
 * @param: aList the list we are swapping.
 * @param: i the first index to swap.
 * @param: j the second param to swap.
 * 
 */

 bool swap(ListInterface<int>& aList, int i, int j){
    // make sure in bounds
    if (i < 1 || i > aList.getLength() || j < 1 || j > aList.getLength()){
        return false;
    }

    // create temp variable to swap values.
    int temp = aList.getEntry(i);
    aList.replace(i, aList.getEntry(j));
    aList.replace(j, temp);
    return true;
 }

/** @brief: reverse the order of a list.
 * @param: aList the list we traverse and reverse.
 * @return: true if successful.
 */

 bool reverse(ListInterface<int>& aList){
    // if (aList.getLength() < 2){
    //    return true;
    // }
    for (int i = 1; i <= aList.getLength()/2; i++){
        swap(aList, i, aList.getLength() - i + 1);
    }
    return true;
 }

 /**
  * @brief: removes one instance ofentries from the list
  * @param: target, the value to be removed
  * @param: aList, the list we are removing from
  * @return: true if removed
  */

  bool remove(ListInterface<int>& aList, int target){
    for (int i = 1; i <= aList.getLength(); i++){
        if (aList.getEntry(i) == target){
            aList.remove(i);
            return true;
        }
    }
    return false;
  }

  /** @brief: removes all instances ofentries from the list
   * @param: target, the value to be removed
   * @param: aList, the list we are removing from
   * @return: true if any were removed
   */
  bool removeAll(ListInterface<int>& aList, int target){
    bool removed = false;
    for (int i = 1; i <= aList.getLength(); i++){
        if (aList.getEntry(i) == target){
            aList.remove(i);
            removed = true;
            i--; // decrement to check the new value at this index
        }
    }
    return removed;
  }