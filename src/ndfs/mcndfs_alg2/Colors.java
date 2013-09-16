package ndfs.mcndfs_alg2;



import java.util.Map;

import graph.State;



class <KeyType, ValueType> MapWithDefaultValues {



    private Map<KeyType, ValueType> map;
    ValueType defaultValue;
    


    MapWithDefaultValues(Map<KeyType, ValueType> map, ValueType defaultValue) {
        this.map = map;
	this.defaultValue = defaultValue;
    }


    boolean hasKeyValuePair(KeyType key,ValueType value) {
       ValueType v = map.get(key);
       return (value == v) || (v==null || value==defaultValue) ;
    }


    synchronized void color(State state, Color color) {
        map.put(state, color);
    }
}
