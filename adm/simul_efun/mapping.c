/*
  mapping.c
  
  Various mapping functions. Some of these are old efuns that are deprecated by driver update.
  
  -- Tlaloc --
*/

//Removes a key from mapping
mapping m_delete(mapping map, mixed key)
{   
    if(!mapp(map))
        return ([  ]);
    
    if(!key)
        return map;
    
    map_delete(map, key);
    
    return map;
}

//Adds a key to mapping with data value
mapping m_add(mapping map, mixed key, mixed data)
{
    if(!mapp(map))
        return ([  ]);
    
    if(!key || !data)
        return map;
    
    map += ([ key : data ]);
    
    return map;
}

//Returns the keys of the mapping
mixed *m_indices(mapping map)
{
    if(!mapp(map))
        return ({  });
    
    return keys(map);
}
    
