**Devin Brousard**  
s218014  
Code Design and Data Structures  
Key/Value Pair Dictionary
  
## **I. Design:**
### 1. System Architecture: 
* The dictionary is composed of items created that each contain a key and value. These items are then stored inside of an item array inside of the dictionary, and the keys are used to access the data.
### 2. Object Information:
*  File name: Dictionary.h (templated: typename TKey, typename TValue)
    * Name: Dictionary&lt;TKey, TValue>()
      * Description: Creates a dictionary with default values
      * Visibility: Public
      * Arguments: None
    * Name: Dictionary&lt;TKey, TValue>()
      * Description: Creates a dictionary and copies the values of the given dictionary onto it
      * Visibility: Public
      * Arguments: const Dictionary<&lt;typename TKey, typename TValue>& other
    * Name: clear()
      * Description: Deletes all items in the dictionary
      * Visibility: Public
      * Arguments: None
    * Name: containsKey(bool) const
      * Description: Checks tosee if this dictionary contains an item with the key given
      * Visibility: Public
      * Arguments:const TKey key
    * Name: containsValue(bool) const
      * Description: Checks to see if one of the dictionary's items have the value given
      * Visibility: Public
      * Arguments:const TValue value
    * Name: tryGetValue(bool) const
      * Description: Checks to see if the function contains a key, and if so, changes second argument to match the key's value
      * Visibility: Public
      * Arguments:const TKey key, TValue& value)
    * Name: addItem()
      * Description: Adds an item to the array of items
      * Visibility: Public
      * Arguments:const TKey& key, const TValue& value
    * Name: remove(bool)
      * Description:Removes an item from the array of items
      * Visibility: Public
      * Arguments:const Tkey key
    * Name: remove(bool)
      * Description: REmoves an item from the array of items, and if successful, changes the second argument to match the key's value
      * Visibility: Public
      * Arguments: const TKey key, TValue& value
    * Name: getCount(int) const
      * Description: Returns the item count
      * Visibility: Public
      * Arguments: None
    * Name: operator =(Dictionary&lt;TKey, TValue>&)
      * Description: Sets this dictionary to be equal to another by copying its items
      * Visibility: Public
      * Arguments:const Dictionary&lt;Tkey, TValue>& other
    * Name: operator [] (TValue)
      * Description: Returns the value with the key given
      * Visibility: Public
      * Arguments:TValue
    * Name: m_itemCount(int)
      * Description: The amount of items in the dictionary 
      * Visibility: Private
    * Name: m_items(Item*)
      * Description: An array of the items that store a key and a value
      * Visibility: Private
    * Name: Item(struct)(Private)
      * Name: key(TKey)
        * Description: THe key that accesses the value
        * Visibility: Public
      * Name: value(TValue)
        * Description: The value that is accessed by the key
        * Visibility: Public