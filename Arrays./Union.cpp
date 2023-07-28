int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector

  while (i < n && j < m) {  //iterating towards end
    if (arr1[i] <= arr2[j]) // if element in first arr is smaller
    {
      if (Union.size() == 0 || Union.back() != arr1[i])  //inserting first element || if previous element is not present in union arr
        Union.push_back(arr1[i]);
      i++;
    } else 
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}
