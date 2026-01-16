/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
function areMapsEqual(map1, map2) {
    if (map1.size !== map2.size) return false;
  
    for (const [key, val] of map1) {
      if (map2.get(key) !== val) return false;
    }
    return true;
  }
  
  var isAnagram = function(s, t) {
    if (s.length !== t.length) return false;
  
    const map = new Map();
    const map1 = new Map();
  
    for (let c of s) {
      map.set(c, (map.get(c) || 0) + 1);
    }
  
    for (let c of t) {
      map1.set(c, (map1.get(c) || 0) + 1);
    }
  
    return areMapsEqual(map, map1);
  };
  
  console.log(isAnagram("anagram", "nagaram")); // true
  