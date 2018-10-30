/* Generated by Frama-C */
void simple_loop(void)
{
  int sum;
  sum = 0;
  {
    int i;
    i = 0;
    {
      int __gen_e_acsl_and;
      if (0 <= i) __gen_e_acsl_and = i <= 10; else __gen_e_acsl_and = 0;
      __e_acsl_assert(__gen_e_acsl_and,(char *)"Invariant",
                      (char *)"simple_loop",(char *)"0 <= i <= 10",8);
      /*@ loop invariant 0 ≤ i ≤ 10; */
      while (i < 10) {
        sum += i;
        {
          int __gen_e_acsl_and_2;
          i ++;
          if (0 <= i) __gen_e_acsl_and_2 = i <= 10;
          else __gen_e_acsl_and_2 = 0;
          __e_acsl_assert(__gen_e_acsl_and_2,(char *)"Invariant",
                          (char *)"simple_loop",(char *)"0 <= i <= 10",8);
        }
      }
    }
  }
  return;
}

void nested_loops(void)
{
  int t[10][15];
  int i;
  i = 0;
  {
    int __gen_e_acsl_and;
    if (0 <= i) __gen_e_acsl_and = i <= 10; else __gen_e_acsl_and = 0;
    __e_acsl_assert(__gen_e_acsl_and,(char *)"Invariant",
                    (char *)"nested_loops",(char *)"0 <= i <= 10",15);
    /*@ loop invariant 0 ≤ i ≤ 10; */
    while (i < 10) {
      {
        int j;
        j = 0;
        {
          int __gen_e_acsl_forall;
          int __gen_e_acsl_k;
          int __gen_e_acsl_l;
          int __gen_e_acsl_and_2;
          __gen_e_acsl_forall = 1;
          __gen_e_acsl_k = 0;
          while (1) {
            if (__gen_e_acsl_k < i) ; else break;
            __gen_e_acsl_l = 0;
            while (1) {
              if (__gen_e_acsl_l < j) ; else break;
              __e_acsl_assert((unsigned int)((unsigned long)__gen_e_acsl_l) < 15U,
                              (char *)"RTE",(char *)"nested_loops",
                              (char *)"index_bound: (unsigned long)__gen_e_acsl_l < 15",
                              19);
              __e_acsl_assert((unsigned int)((unsigned long)__gen_e_acsl_k) < 10U,
                              (char *)"RTE",(char *)"nested_loops",
                              (char *)"index_bound: (unsigned long)__gen_e_acsl_k < 10",
                              19);
              if (t[(unsigned long)__gen_e_acsl_k][(unsigned long)__gen_e_acsl_l] == 
                  __gen_e_acsl_k * __gen_e_acsl_l) ;
              else {
                __gen_e_acsl_forall = 0;
                goto e_acsl_end_loop1;
              }
              __gen_e_acsl_l = (int)(__gen_e_acsl_l + 1L);
            }
            __gen_e_acsl_k = (int)(__gen_e_acsl_k + 1L);
          }
          e_acsl_end_loop1: ;
          __e_acsl_assert(__gen_e_acsl_forall,(char *)"Invariant",
                          (char *)"nested_loops",
                          (char *)"\\forall integer k, integer l; 0 <= k < i && 0 <= l < j ==> t[k][l] == k*l",
                          19);
          if (0 <= j) __gen_e_acsl_and_2 = j <= 15;
          else __gen_e_acsl_and_2 = 0;
          __e_acsl_assert(__gen_e_acsl_and_2,(char *)"Invariant",
                          (char *)"nested_loops",(char *)"0 <= j <= 15",17);
          /*@ loop invariant 0 ≤ j ≤ 15;
              loop invariant
                ∀ ℤ k, ℤ l;
                  0 ≤ k < i ∧ 0 ≤ l < j ⇒ t[k][l] ≡ k*l;
          */
          while (j < 15) {
            t[i][j] = i * j;
            {
              int __gen_e_acsl_and_3;
              int __gen_e_acsl_forall_2;
              int __gen_e_acsl_k_2;
              int __gen_e_acsl_l_2;
              j ++;
              if (0 <= j) __gen_e_acsl_and_3 = j <= 15;
              else __gen_e_acsl_and_3 = 0;
              __e_acsl_assert(__gen_e_acsl_and_3,(char *)"Invariant",
                              (char *)"nested_loops",(char *)"0 <= j <= 15",
                              17);
              __gen_e_acsl_forall_2 = 1;
              __gen_e_acsl_k_2 = 0;
              while (1) {
                if (__gen_e_acsl_k_2 < i) ; else break;
                __gen_e_acsl_l_2 = 0;
                while (1) {
                  if (__gen_e_acsl_l_2 < j) ; else break;
                  __e_acsl_assert((unsigned int)((unsigned long)__gen_e_acsl_l_2) < 15U,
                                  (char *)"RTE",(char *)"nested_loops",
                                  (char *)"index_bound: (unsigned long)__gen_e_acsl_l_2 < 15",
                                  19);
                  __e_acsl_assert((unsigned int)((unsigned long)__gen_e_acsl_k_2) < 10U,
                                  (char *)"RTE",(char *)"nested_loops",
                                  (char *)"index_bound: (unsigned long)__gen_e_acsl_k_2 < 10",
                                  19);
                  /*@ assert
                      Value: initialisation:
                        \initialized(&t[(unsigned long)__gen_e_acsl_k_2][(unsigned long)__gen_e_acsl_l_2]);
                  */
                  if (t[(unsigned long)__gen_e_acsl_k_2][(unsigned long)__gen_e_acsl_l_2] == 
                      __gen_e_acsl_k_2 * __gen_e_acsl_l_2) ;
                  else {
                    __gen_e_acsl_forall_2 = 0;
                    goto e_acsl_end_loop2;
                  }
                  __gen_e_acsl_l_2 = (int)(__gen_e_acsl_l_2 + 1L);
                }
                __gen_e_acsl_k_2 = (int)(__gen_e_acsl_k_2 + 1L);
              }
              e_acsl_end_loop2: ;
              __e_acsl_assert(__gen_e_acsl_forall_2,(char *)"Invariant",
                              (char *)"nested_loops",
                              (char *)"\\forall integer k, integer l; 0 <= k < i && 0 <= l < j ==> t[k][l] == k*l",
                              19);
            }
          }
        }
      }
      {
        int __gen_e_acsl_and_4;
        i ++;
        if (0 <= i) __gen_e_acsl_and_4 = i <= 10;
        else __gen_e_acsl_and_4 = 0;
        __e_acsl_assert(__gen_e_acsl_and_4,(char *)"Invariant",
                        (char *)"nested_loops",(char *)"0 <= i <= 10",15);
      }
    }
  }
  return;
}

void unnatural_loop(void)
{
  int x;
  x = 0;
  {
    int i;
    i = 0;
    {
      int __gen_e_acsl_and;
      if (0 <= i) __gen_e_acsl_and = i <= 6; else __gen_e_acsl_and = 0;
      __e_acsl_assert(__gen_e_acsl_and,(char *)"Invariant",
                      (char *)"unnatural_loop",(char *)"0 <= i <= 6",26);
      /*@ loop invariant 0 ≤ i ≤ 6; */
      while (i < 10) {
        if (x == 5) break;
        x = i;
        {
          int __gen_e_acsl_and_2;
          i ++;
          if (0 <= i) __gen_e_acsl_and_2 = i <= 6;
          else __gen_e_acsl_and_2 = 0;
          __e_acsl_assert(__gen_e_acsl_and_2,(char *)"Invariant",
                          (char *)"unnatural_loop",(char *)"0 <= i <= 6",26);
        }
      }
    }
  }
  return;
}

int main(void)
{
  int __retres;
  simple_loop();
  nested_loops();
  unnatural_loop();
  __retres = 0;
  return __retres;
}

