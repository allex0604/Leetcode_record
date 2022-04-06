​time : O(n^2)

​base case

      (1) If array size is < 3, means no triplet would exist from that array. Return empty vector of vectors.
      (2) (condtinal) If first element is more than 0, Return empty vector of vectors.

​key point : need sort array

​avoid duplicate triplets
 
      if match 3sunm, 先忽略與第2與第3個相同的element,最後在忽略第1個相同的element,就可以保證不會有相同的
