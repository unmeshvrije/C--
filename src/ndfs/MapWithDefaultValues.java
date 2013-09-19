package ndfs;

import java.util.HashMap;

import graph.State;

/*
 * This class is very much like a hashmap, 
 * It stores default values for keys which don't pre-exist in the hash map.
 */
public class MapWithDefaultValues<KeyType, ValueType>{

  private HashMap<KeyType, ValueType> hashMap;
  private ValueType defaultValue;

  public MapWithDefaultValues(HashMap<KeyType, ValueType> hashMap, ValueType defaultValue){
    this.hashMap = hashMap;
    this.defaultValue = defaultValue;
  }

  public synchronized void setValueSynchronized(KeyType key,ValueType value){
    hashMap.put(key,value);
  }

  public void setValue(KeyType key,ValueType value){
    hashMap.put(key,value);
  }

  // TODO: make const method
  public ValueType getValue(KeyType key){
  
    if (null == this.hashMap.get(key) ) {
      this.setValue(key, defaultValue);
    }
    
    return this.hashMap.get(key);
  }

  /* returns true if either
   * - (key,value) pair is in hashmap
   * - (key,value) pair is not in hashmap AND the requested value is the default value 
   */
  public boolean hasKeyValuePair(KeyType key,ValueType value){
    ValueType v = getValue(key);
    return v.equals(value);
  }

}
