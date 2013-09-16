package ndfs.mcndfs_alg2;



import java.util.HashMap;

import graph.State;



public class MapWithDefaultValues<KeyType, ValueType> {



    private HashMap<KeyType, ValueType> hashmap;
    ValueType defaultValue;
    


    MapWithDefaultValues(HashMap<KeyType, ValueType> hashmap, ValueType defaultValue){
        this.hashmap = hashmap;
	      this.defaultValue = defaultValue;
    }

    boolean hasKeyValuePair(KeyType key,ValueType value){
       ValueType v = hashmap.get(key);
       return (v == value) || (v==null || value==defaultValue);
    }


    synchronized void setValue(KeyType key,ValueType value){
        hashmap.put(key,value);
    }
}
