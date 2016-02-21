#ifndef __KAIFENG_QUEST__
#define __KAIFENG_QUEST__

#define INDEXDELTA 20

#define IDX_TYPE 0
#define IDX_NAME 1
#define IDX_ID   2
#define IDX_OBJ  3
#define IDX_AMT  4

int* m_keys;
int *order_list (int *list)
{
  int i, j;
  int size = sizeof(list);
        
  for (i = size-2; i >= 0; i--)
  {
    for (j = 0; j <= i; j++)
    {
      reset_eval_cost();
      if (list[j] > list[j+1])
      {
        int k = list[j];
        list[j] = list[j+1];
        list[j+1] = k;
      }
    }
  }
  return list;
}

int quest_accurate_index (int *quest_keys, int daoxing)
{
  int i = 0;
  int j = 0;
  int k = sizeof(quest_keys)-1;

  while (i < k)
  {
    // reset_eval_cost();
    j = (k-i)/2+i;
    if (quest_keys[j] == daoxing)
    {
      return j;
    }  
    else if (quest_keys[j] > daoxing)
    {
      k = j - 1;
    }  
    else
    {
      i = j + 1;
    }  
  }
  return j;
}

int quest_random_index (int *quest_keys, int i)
{
  int lower;
  int upper;
  int size = sizeof (quest_keys);

  lower = i - INDEXDELTA;
  upper = i + INDEXDELTA;

  if (lower < 0)lower = 0;
  if (upper >= size) upper = size - 1;

  // adjust here, allow access to lower quests:
  lower = upper/4;
  if (upper - lower < INDEXDELTA)lower = 0;
  return(lower+random(upper-lower));
}

int log10 (int i)
{
  int j = 0;
  while (i = i/10)
    j++;
  return j;
}

#endif

