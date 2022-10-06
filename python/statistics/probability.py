#!/usr/bin/env python
# coding: utf-8

# In[132]:


import math
import fraction
import importlib
from typing import Union


# In[181]:


importlib.reload(fraction)
from fraction import arrange, frac, merge, frac_pow


# In[106]:


def combination(n, p):
    return frac(composite=(arrange(n), merge(arrange(p), arrange(n, p))))


# In[158]:


def bernoulli(p: Union[float, frac], x) -> Union[float, frac]:
    if not 0 <= p <= 1:
        raise ValueError("p should be between 0 and 1.")
    return frac_pow(p, x) * frac_pow((1 - p), 1 - x)


# In[162]:


def binomial(p: Union[float, frac], n: int, y) -> Union[float, frac]:
    return combination(n, y) * frac_pow(p, y) * frac_pow(1 - p, n - y)


# In[ ]:


def geometric(p: Union[float, frac], x: int) -> Union[float, frac]:
    return p * frac_pow(1 - p, x - 1)


# In[175]:


def negative(p: Union[float, frac], k: int, x: int) -> Union[float, frac]:
    return combination(x - 1, k - 1) * frac_pow(p, k) * frac_pow(1 - p, x - k)


# In[178]:


def hypergeometric(N, k, n, x) -> Union[float, frac]:
    return (combination(k, x) * combination(N - k, n - x)) / combination(N, n)


# In[179]:


print(bernoulli(frac(1, 10), 2))
print(binomial(frac(2, 10), n=3, y=1))
print(negative(frac(48, 67), k = 3, x = 2))


# In[189]:


print(combination(118, 18))


# In[ ]:


print(hypergeometric(118, 110, 18, 3))

