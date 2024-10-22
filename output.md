```python
import pandas as pd

```


```python
from sklearn.linear_model import LinearRegression
import numpy as np
```


```python
import os
print(os.listdir())  # List all files in the current directory


```

    ['Untitled1.ipynb', '.DS_Store', 'python', '.localized', 'Untitled.ipynb', 'aathma rama.band', 'GitHub', 'MATLAB', '.ipynb_checkpoints', 'aathma rama - 03:05:23, 4.36 PM. 2.mp3']



```python
import os
print(os.listdir())  # List all files in the current directory
```

    ['Untitled1.ipynb', '.DS_Store', 'python', '.localized', 'Untitled.ipynb', 'aathma rama.band', 'GitHub', 'Traffic_Counts_2011-2012.csv', 'MATLAB', '.ipynb_checkpoints', 'aathma rama - 03:05:23, 4.36 PM. 2.mp3']



```python
data = pd.read_csv('Traffic_Counts_2011-2012.csv')
```


```python
data.head()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>Roadway Name</th>
      <th>From</th>
      <th>To</th>
      <th>Direction</th>
      <th>Date</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/09/2012</td>
      <td>20</td>
      <td>10</td>
      <td>11</td>
      <td>...</td>
      <td>104.0</td>
      <td>105.0</td>
      <td>147.0</td>
      <td>120.0</td>
      <td>91.0</td>
      <td>83.0</td>
      <td>74.0</td>
      <td>49.0</td>
      <td>42.0</td>
      <td>42.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/10/2012</td>
      <td>21</td>
      <td>16</td>
      <td>8</td>
      <td>...</td>
      <td>102.0</td>
      <td>98.0</td>
      <td>133.0</td>
      <td>131.0</td>
      <td>95.0</td>
      <td>73.0</td>
      <td>70.0</td>
      <td>63.0</td>
      <td>42.0</td>
      <td>35.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/11/2012</td>
      <td>27</td>
      <td>14</td>
      <td>6</td>
      <td>...</td>
      <td>115.0</td>
      <td>115.0</td>
      <td>130.0</td>
      <td>143.0</td>
      <td>106.0</td>
      <td>89.0</td>
      <td>68.0</td>
      <td>64.0</td>
      <td>56.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/12/2012</td>
      <td>22</td>
      <td>7</td>
      <td>7</td>
      <td>...</td>
      <td>71.0</td>
      <td>127.0</td>
      <td>122.0</td>
      <td>144.0</td>
      <td>122.0</td>
      <td>76.0</td>
      <td>64.0</td>
      <td>58.0</td>
      <td>64.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/13/2012</td>
      <td>31</td>
      <td>17</td>
      <td>7</td>
      <td>...</td>
      <td>113.0</td>
      <td>126.0</td>
      <td>133.0</td>
      <td>135.0</td>
      <td>102.0</td>
      <td>106.0</td>
      <td>58.0</td>
      <td>58.0</td>
      <td>55.0</td>
      <td>54.0</td>
    </tr>
  </tbody>
</table>
<p>5 rows × 31 columns</p>
</div>




```python
data.tail()

```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>Roadway Name</th>
      <th>From</th>
      <th>To</th>
      <th>Direction</th>
      <th>Date</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>3388</th>
      <td>3389</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/10/2012</td>
      <td>6</td>
      <td>4</td>
      <td>7</td>
      <td>...</td>
      <td>24.0</td>
      <td>54.0</td>
      <td>32.0</td>
      <td>21.0</td>
      <td>27.0</td>
      <td>23.0</td>
      <td>20.0</td>
      <td>22.0</td>
      <td>10.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>3389</th>
      <td>3390</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/11/2012</td>
      <td>7</td>
      <td>4</td>
      <td>4</td>
      <td>...</td>
      <td>27.0</td>
      <td>39.0</td>
      <td>38.0</td>
      <td>32.0</td>
      <td>39.0</td>
      <td>28.0</td>
      <td>28.0</td>
      <td>17.0</td>
      <td>16.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3390</th>
      <td>3391</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/12/2012</td>
      <td>5</td>
      <td>2</td>
      <td>5</td>
      <td>...</td>
      <td>33.0</td>
      <td>69.0</td>
      <td>35.0</td>
      <td>30.0</td>
      <td>29.0</td>
      <td>30.0</td>
      <td>24.0</td>
      <td>13.0</td>
      <td>11.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>3391</th>
      <td>3392</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/13/2012</td>
      <td>6</td>
      <td>5</td>
      <td>8</td>
      <td>...</td>
      <td>31.0</td>
      <td>59.0</td>
      <td>35.0</td>
      <td>26.0</td>
      <td>26.0</td>
      <td>20.0</td>
      <td>24.0</td>
      <td>19.0</td>
      <td>18.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3392</th>
      <td>3393</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/14/2012</td>
      <td>11</td>
      <td>11</td>
      <td>7</td>
      <td>...</td>
      <td>26.0</td>
      <td>25.0</td>
      <td>27.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
    </tr>
  </tbody>
</table>
<p>5 rows × 31 columns</p>
</div>




```python
data.info()
```

    <class 'pandas.core.frame.DataFrame'>
    RangeIndex: 3393 entries, 0 to 3392
    Data columns (total 31 columns):
     #   Column         Non-Null Count  Dtype  
    ---  ------         --------------  -----  
     0   ID             3393 non-null   int64  
     1   GIS ID         3393 non-null   int64  
     2   Roadway Name   3393 non-null   object 
     3   From           3393 non-null   object 
     4   To             3393 non-null   object 
     5   Direction      3393 non-null   object 
     6   Date           3393 non-null   object 
     7   12:00-1:00 AM  3393 non-null   int64  
     8   1:00-2:00AM    3393 non-null   int64  
     9   2:00-3:00AM    3393 non-null   int64  
     10  3:00-4:00AM    3393 non-null   int64  
     11  4:00-5:00AM    3393 non-null   int64  
     12  5:00-6:00AM    3393 non-null   int64  
     13  6:00-7:00AM    3393 non-null   int64  
     14  7:00-8:00AM    3393 non-null   int64  
     15  8:00-9:00AM    3393 non-null   int64  
     16  9:00-10:00AM   3393 non-null   int64  
     17  10:00-11:00AM  3393 non-null   int64  
     18  11:00-12:00PM  3393 non-null   int64  
     19  12:00-1:00PM   3140 non-null   float64
     20  1:00-2:00PM    3140 non-null   float64
     21  2:00-3:00PM    3140 non-null   float64
     22  3:00-4:00PM    3140 non-null   float64
     23  4:00-5:00PM    3140 non-null   float64
     24  5:00-6:00PM    3140 non-null   float64
     25  6:00-7:00PM    3140 non-null   float64
     26  7:00-8:00PM    3140 non-null   float64
     27  8:00-9:00PM    3140 non-null   float64
     28  9:00-10:00PM   3140 non-null   float64
     29  10:00-11:00PM  3140 non-null   float64
     30  11:00-12:00AM  3140 non-null   float64
    dtypes: float64(12), int64(14), object(5)
    memory usage: 821.9+ KB



```python
data.describe()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>3:00-4:00AM</th>
      <th>4:00-5:00AM</th>
      <th>5:00-6:00AM</th>
      <th>6:00-7:00AM</th>
      <th>7:00-8:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>count</th>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>3393.000000</td>
      <td>...</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
      <td>3140.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>1697.000000</td>
      <td>69728.759505</td>
      <td>101.795756</td>
      <td>66.419688</td>
      <td>49.033893</td>
      <td>42.634247</td>
      <td>55.322429</td>
      <td>96.768052</td>
      <td>202.911583</td>
      <td>366.245800</td>
      <td>...</td>
      <td>364.927389</td>
      <td>405.768790</td>
      <td>408.199363</td>
      <td>411.295223</td>
      <td>367.060828</td>
      <td>303.625159</td>
      <td>243.284395</td>
      <td>199.435987</td>
      <td>161.675159</td>
      <td>127.013376</td>
    </tr>
    <tr>
      <th>std</th>
      <td>979.619059</td>
      <td>39720.749635</td>
      <td>96.973304</td>
      <td>69.539668</td>
      <td>55.143945</td>
      <td>51.341276</td>
      <td>64.557344</td>
      <td>115.331687</td>
      <td>228.621699</td>
      <td>325.066892</td>
      <td>...</td>
      <td>296.925241</td>
      <td>337.763846</td>
      <td>346.564572</td>
      <td>351.184241</td>
      <td>319.304833</td>
      <td>267.100687</td>
      <td>215.554661</td>
      <td>180.260676</td>
      <td>155.010488</td>
      <td>129.900623</td>
    </tr>
    <tr>
      <th>min</th>
      <td>1.000000</td>
      <td>646.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>...</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>849.000000</td>
      <td>45137.000000</td>
      <td>46.000000</td>
      <td>27.000000</td>
      <td>19.000000</td>
      <td>16.000000</td>
      <td>20.000000</td>
      <td>36.000000</td>
      <td>78.000000</td>
      <td>160.000000</td>
      <td>...</td>
      <td>180.000000</td>
      <td>201.000000</td>
      <td>201.750000</td>
      <td>197.000000</td>
      <td>169.750000</td>
      <td>136.000000</td>
      <td>101.750000</td>
      <td>83.000000</td>
      <td>64.000000</td>
      <td>45.000000</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>1697.000000</td>
      <td>71645.000000</td>
      <td>78.000000</td>
      <td>49.000000</td>
      <td>34.000000</td>
      <td>29.000000</td>
      <td>38.000000</td>
      <td>65.000000</td>
      <td>138.000000</td>
      <td>279.000000</td>
      <td>...</td>
      <td>310.000000</td>
      <td>352.000000</td>
      <td>353.000000</td>
      <td>353.500000</td>
      <td>315.000000</td>
      <td>265.000000</td>
      <td>209.000000</td>
      <td>172.000000</td>
      <td>134.500000</td>
      <td>103.000000</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>2545.000000</td>
      <td>88779.000000</td>
      <td>125.000000</td>
      <td>83.000000</td>
      <td>61.000000</td>
      <td>52.000000</td>
      <td>65.000000</td>
      <td>110.000000</td>
      <td>239.000000</td>
      <td>472.000000</td>
      <td>...</td>
      <td>482.000000</td>
      <td>534.000000</td>
      <td>541.250000</td>
      <td>540.250000</td>
      <td>485.000000</td>
      <td>407.000000</td>
      <td>327.000000</td>
      <td>267.000000</td>
      <td>214.000000</td>
      <td>170.000000</td>
    </tr>
    <tr>
      <th>max</th>
      <td>3393.000000</td>
      <td>194613.000000</td>
      <td>1143.000000</td>
      <td>974.000000</td>
      <td>794.000000</td>
      <td>673.000000</td>
      <td>690.000000</td>
      <td>964.000000</td>
      <td>2136.000000</td>
      <td>2381.000000</td>
      <td>...</td>
      <td>2377.000000</td>
      <td>3345.000000</td>
      <td>3701.000000</td>
      <td>3751.000000</td>
      <td>3489.000000</td>
      <td>3012.000000</td>
      <td>1944.000000</td>
      <td>1475.000000</td>
      <td>1342.000000</td>
      <td>1327.000000</td>
    </tr>
  </tbody>
</table>
<p>8 rows × 26 columns</p>
</div>




```python
data.fillna(0)
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>Roadway Name</th>
      <th>From</th>
      <th>To</th>
      <th>Direction</th>
      <th>Date</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/09/2012</td>
      <td>20</td>
      <td>10</td>
      <td>11</td>
      <td>...</td>
      <td>104.0</td>
      <td>105.0</td>
      <td>147.0</td>
      <td>120.0</td>
      <td>91.0</td>
      <td>83.0</td>
      <td>74.0</td>
      <td>49.0</td>
      <td>42.0</td>
      <td>42.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/10/2012</td>
      <td>21</td>
      <td>16</td>
      <td>8</td>
      <td>...</td>
      <td>102.0</td>
      <td>98.0</td>
      <td>133.0</td>
      <td>131.0</td>
      <td>95.0</td>
      <td>73.0</td>
      <td>70.0</td>
      <td>63.0</td>
      <td>42.0</td>
      <td>35.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/11/2012</td>
      <td>27</td>
      <td>14</td>
      <td>6</td>
      <td>...</td>
      <td>115.0</td>
      <td>115.0</td>
      <td>130.0</td>
      <td>143.0</td>
      <td>106.0</td>
      <td>89.0</td>
      <td>68.0</td>
      <td>64.0</td>
      <td>56.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/12/2012</td>
      <td>22</td>
      <td>7</td>
      <td>7</td>
      <td>...</td>
      <td>71.0</td>
      <td>127.0</td>
      <td>122.0</td>
      <td>144.0</td>
      <td>122.0</td>
      <td>76.0</td>
      <td>64.0</td>
      <td>58.0</td>
      <td>64.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/13/2012</td>
      <td>31</td>
      <td>17</td>
      <td>7</td>
      <td>...</td>
      <td>113.0</td>
      <td>126.0</td>
      <td>133.0</td>
      <td>135.0</td>
      <td>102.0</td>
      <td>106.0</td>
      <td>58.0</td>
      <td>58.0</td>
      <td>55.0</td>
      <td>54.0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>3388</th>
      <td>3389</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/10/2012</td>
      <td>6</td>
      <td>4</td>
      <td>7</td>
      <td>...</td>
      <td>24.0</td>
      <td>54.0</td>
      <td>32.0</td>
      <td>21.0</td>
      <td>27.0</td>
      <td>23.0</td>
      <td>20.0</td>
      <td>22.0</td>
      <td>10.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>3389</th>
      <td>3390</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/11/2012</td>
      <td>7</td>
      <td>4</td>
      <td>4</td>
      <td>...</td>
      <td>27.0</td>
      <td>39.0</td>
      <td>38.0</td>
      <td>32.0</td>
      <td>39.0</td>
      <td>28.0</td>
      <td>28.0</td>
      <td>17.0</td>
      <td>16.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3390</th>
      <td>3391</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/12/2012</td>
      <td>5</td>
      <td>2</td>
      <td>5</td>
      <td>...</td>
      <td>33.0</td>
      <td>69.0</td>
      <td>35.0</td>
      <td>30.0</td>
      <td>29.0</td>
      <td>30.0</td>
      <td>24.0</td>
      <td>13.0</td>
      <td>11.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>3391</th>
      <td>3392</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/13/2012</td>
      <td>6</td>
      <td>5</td>
      <td>8</td>
      <td>...</td>
      <td>31.0</td>
      <td>59.0</td>
      <td>35.0</td>
      <td>26.0</td>
      <td>26.0</td>
      <td>20.0</td>
      <td>24.0</td>
      <td>19.0</td>
      <td>18.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3392</th>
      <td>3393</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/14/2012</td>
      <td>11</td>
      <td>11</td>
      <td>7</td>
      <td>...</td>
      <td>26.0</td>
      <td>25.0</td>
      <td>27.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
    </tr>
  </tbody>
</table>
<p>3393 rows × 31 columns</p>
</div>




```python
data
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>Roadway Name</th>
      <th>From</th>
      <th>To</th>
      <th>Direction</th>
      <th>Date</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/09/2012</td>
      <td>20</td>
      <td>10</td>
      <td>11</td>
      <td>...</td>
      <td>104.0</td>
      <td>105.0</td>
      <td>147.0</td>
      <td>120.0</td>
      <td>91.0</td>
      <td>83.0</td>
      <td>74.0</td>
      <td>49.0</td>
      <td>42.0</td>
      <td>42.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/10/2012</td>
      <td>21</td>
      <td>16</td>
      <td>8</td>
      <td>...</td>
      <td>102.0</td>
      <td>98.0</td>
      <td>133.0</td>
      <td>131.0</td>
      <td>95.0</td>
      <td>73.0</td>
      <td>70.0</td>
      <td>63.0</td>
      <td>42.0</td>
      <td>35.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/11/2012</td>
      <td>27</td>
      <td>14</td>
      <td>6</td>
      <td>...</td>
      <td>115.0</td>
      <td>115.0</td>
      <td>130.0</td>
      <td>143.0</td>
      <td>106.0</td>
      <td>89.0</td>
      <td>68.0</td>
      <td>64.0</td>
      <td>56.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/12/2012</td>
      <td>22</td>
      <td>7</td>
      <td>7</td>
      <td>...</td>
      <td>71.0</td>
      <td>127.0</td>
      <td>122.0</td>
      <td>144.0</td>
      <td>122.0</td>
      <td>76.0</td>
      <td>64.0</td>
      <td>58.0</td>
      <td>64.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/13/2012</td>
      <td>31</td>
      <td>17</td>
      <td>7</td>
      <td>...</td>
      <td>113.0</td>
      <td>126.0</td>
      <td>133.0</td>
      <td>135.0</td>
      <td>102.0</td>
      <td>106.0</td>
      <td>58.0</td>
      <td>58.0</td>
      <td>55.0</td>
      <td>54.0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>3388</th>
      <td>3389</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/10/2012</td>
      <td>6</td>
      <td>4</td>
      <td>7</td>
      <td>...</td>
      <td>24.0</td>
      <td>54.0</td>
      <td>32.0</td>
      <td>21.0</td>
      <td>27.0</td>
      <td>23.0</td>
      <td>20.0</td>
      <td>22.0</td>
      <td>10.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>3389</th>
      <td>3390</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/11/2012</td>
      <td>7</td>
      <td>4</td>
      <td>4</td>
      <td>...</td>
      <td>27.0</td>
      <td>39.0</td>
      <td>38.0</td>
      <td>32.0</td>
      <td>39.0</td>
      <td>28.0</td>
      <td>28.0</td>
      <td>17.0</td>
      <td>16.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3390</th>
      <td>3391</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/12/2012</td>
      <td>5</td>
      <td>2</td>
      <td>5</td>
      <td>...</td>
      <td>33.0</td>
      <td>69.0</td>
      <td>35.0</td>
      <td>30.0</td>
      <td>29.0</td>
      <td>30.0</td>
      <td>24.0</td>
      <td>13.0</td>
      <td>11.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>3391</th>
      <td>3392</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/13/2012</td>
      <td>6</td>
      <td>5</td>
      <td>8</td>
      <td>...</td>
      <td>31.0</td>
      <td>59.0</td>
      <td>35.0</td>
      <td>26.0</td>
      <td>26.0</td>
      <td>20.0</td>
      <td>24.0</td>
      <td>19.0</td>
      <td>18.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3392</th>
      <td>3393</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/14/2012</td>
      <td>11</td>
      <td>11</td>
      <td>7</td>
      <td>...</td>
      <td>26.0</td>
      <td>25.0</td>
      <td>27.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
    </tr>
  </tbody>
</table>
<p>3393 rows × 31 columns</p>
</div>




```python
data.dropna()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>ID</th>
      <th>GIS ID</th>
      <th>Roadway Name</th>
      <th>From</th>
      <th>To</th>
      <th>Direction</th>
      <th>Date</th>
      <th>12:00-1:00 AM</th>
      <th>1:00-2:00AM</th>
      <th>2:00-3:00AM</th>
      <th>...</th>
      <th>2:00-3:00PM</th>
      <th>3:00-4:00PM</th>
      <th>4:00-5:00PM</th>
      <th>5:00-6:00PM</th>
      <th>6:00-7:00PM</th>
      <th>7:00-8:00PM</th>
      <th>8:00-9:00PM</th>
      <th>9:00-10:00PM</th>
      <th>10:00-11:00PM</th>
      <th>11:00-12:00AM</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/09/2012</td>
      <td>20</td>
      <td>10</td>
      <td>11</td>
      <td>...</td>
      <td>104.0</td>
      <td>105.0</td>
      <td>147.0</td>
      <td>120.0</td>
      <td>91.0</td>
      <td>83.0</td>
      <td>74.0</td>
      <td>49.0</td>
      <td>42.0</td>
      <td>42.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/10/2012</td>
      <td>21</td>
      <td>16</td>
      <td>8</td>
      <td>...</td>
      <td>102.0</td>
      <td>98.0</td>
      <td>133.0</td>
      <td>131.0</td>
      <td>95.0</td>
      <td>73.0</td>
      <td>70.0</td>
      <td>63.0</td>
      <td>42.0</td>
      <td>35.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/11/2012</td>
      <td>27</td>
      <td>14</td>
      <td>6</td>
      <td>...</td>
      <td>115.0</td>
      <td>115.0</td>
      <td>130.0</td>
      <td>143.0</td>
      <td>106.0</td>
      <td>89.0</td>
      <td>68.0</td>
      <td>64.0</td>
      <td>56.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/12/2012</td>
      <td>22</td>
      <td>7</td>
      <td>7</td>
      <td>...</td>
      <td>71.0</td>
      <td>127.0</td>
      <td>122.0</td>
      <td>144.0</td>
      <td>122.0</td>
      <td>76.0</td>
      <td>64.0</td>
      <td>58.0</td>
      <td>64.0</td>
      <td>43.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>15540</td>
      <td>BEACH STREET</td>
      <td>UNION PLACE</td>
      <td>VAN DUZER STREET</td>
      <td>NB</td>
      <td>01/13/2012</td>
      <td>31</td>
      <td>17</td>
      <td>7</td>
      <td>...</td>
      <td>113.0</td>
      <td>126.0</td>
      <td>133.0</td>
      <td>135.0</td>
      <td>102.0</td>
      <td>106.0</td>
      <td>58.0</td>
      <td>58.0</td>
      <td>55.0</td>
      <td>54.0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>3388</th>
      <td>3389</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/10/2012</td>
      <td>6</td>
      <td>4</td>
      <td>7</td>
      <td>...</td>
      <td>24.0</td>
      <td>54.0</td>
      <td>32.0</td>
      <td>21.0</td>
      <td>27.0</td>
      <td>23.0</td>
      <td>20.0</td>
      <td>22.0</td>
      <td>10.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>3389</th>
      <td>3390</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/11/2012</td>
      <td>7</td>
      <td>4</td>
      <td>4</td>
      <td>...</td>
      <td>27.0</td>
      <td>39.0</td>
      <td>38.0</td>
      <td>32.0</td>
      <td>39.0</td>
      <td>28.0</td>
      <td>28.0</td>
      <td>17.0</td>
      <td>16.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3390</th>
      <td>3391</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/12/2012</td>
      <td>5</td>
      <td>2</td>
      <td>5</td>
      <td>...</td>
      <td>33.0</td>
      <td>69.0</td>
      <td>35.0</td>
      <td>30.0</td>
      <td>29.0</td>
      <td>30.0</td>
      <td>24.0</td>
      <td>13.0</td>
      <td>11.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>3391</th>
      <td>3392</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/13/2012</td>
      <td>6</td>
      <td>5</td>
      <td>8</td>
      <td>...</td>
      <td>31.0</td>
      <td>59.0</td>
      <td>35.0</td>
      <td>26.0</td>
      <td>26.0</td>
      <td>20.0</td>
      <td>24.0</td>
      <td>19.0</td>
      <td>18.0</td>
      <td>13.0</td>
    </tr>
    <tr>
      <th>3392</th>
      <td>3393</td>
      <td>7886</td>
      <td>WILLOWBROOK ROAD</td>
      <td>SENECA LOOP</td>
      <td>COLLFIELD AVENUE</td>
      <td>WB</td>
      <td>01/14/2012</td>
      <td>11</td>
      <td>11</td>
      <td>7</td>
      <td>...</td>
      <td>26.0</td>
      <td>25.0</td>
      <td>27.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
      <td>0.0</td>
    </tr>
  </tbody>
</table>
<p>3140 rows × 31 columns</p>
</div>




```python
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

# Assuming 'data' is your DataFrame

# Extract 'day_of_week' from the 'Date' column
data['day_of_week'] = pd.to_datetime(data['Date']).dt.dayofweek

# Reshape the DataFrame to have a 'hour' column and traffic volumes as rows
hourly_columns = ['12:00-1:00 AM', '1:00-2:00AM', '2:00-3:00AM', '3:00-4:00AM', '4:00-5:00AM',
                  '5:00-6:00AM', '6:00-7:00AM', '7:00-8:00AM', '8:00-9:00AM', '9:00-10:00AM',
                  '10:00-11:00AM', '11:00-12:00PM', '12:00-1:00PM', '1:00-2:00PM', '2:00-3:00PM',
                  '3:00-4:00PM', '4:00-5:00PM', '5:00-6:00PM', '6:00-7:00PM', '7:00-8:00PM',
                  '8:00-9:00PM', '9:00-10:00PM', '10:00-11:00PM', '11:00-12:00AM']

# Stack the hourly traffic columns
data_melted = data.melt(id_vars=['Date', 'day_of_week'], 
                        value_vars=hourly_columns, 
                        var_name='hour', 
                        value_name='traffic_volume')

# Create a numeric 'hour' column from the time range string (optional)
data_melted['hour'] = data_melted['hour'].str.extract(r'(\d{1,2}):')[0].astype(int)

# Remove rows with NaN values in 'traffic_volume'
data_melted.dropna(subset=['traffic_volume'], inplace=True)

# Now X will contain 'hour' and 'day_of_week', and y will be 'traffic_volume'
X = data_melted[['hour', 'day_of_week']].values
y = data_melted['traffic_volume'].values

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=10)

# Train a linear regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Define a prediction function
def predict_traffic(location, hour, day_of_week):
    prediction = model.predict(np.array([[hour, day_of_week]]))
    return {'location': location, 'predicted_traffic': prediction[0]}


print(result)

```

    {'location': 'Main Street', 'predicted_traffic': 299.10853475092875}



```python
import matplotlib.pyplot as plt

# Data for traffic prediction
hours = ['8 AM', '9 AM', '10 AM', '5 PM', '6 PM']
predicted_volume = [120, 150, 100, 200, 250]

# Create a line plot
plt.figure(figsize=(10, 5))
plt.plot(hours, predicted_volume, marker='o', linestyle='-', color='blue')
plt.title('Predicted Traffic Volume from City A to City B')
plt.xlabel('Time of Day')
plt.ylabel('Predicted Traffic Volume (vehicles)')
plt.xticks(rotation=45)
plt.grid()
plt.tight_layout()

# Show the plot
plt.show()

```


    
![png](output_13_0.png)
    



```python
# Ensure you have imported the necessary libraries
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

# Load your data
data = pd.read_csv('Traffic_Counts_2011-2012.csv')

# Data preprocessing
data['day_of_week'] = pd.to_datetime(data['Date']).dt.dayofweek

hourly_columns = ['12:00-1:00 AM', '1:00-2:00AM', '2:00-3:00AM', '3:00-4:00AM', '4:00-5:00AM',
                  '5:00-6:00AM', '6:00-7:00AM', '7:00-8:00AM', '8:00-9:00AM', '9:00-10:00AM',
                  '10:00-11:00AM', '11:00-12:00PM', '12:00-1:00PM', '1:00-2:00PM', '2:00-3:00PM',
                  '3:00-4:00PM', '4:00-5:00PM', '5:00-6:00PM', '6:00-7:00PM', '7:00-8:00PM',
                  '8:00-9:00PM', '9:00-10:00PM', '10:00-11:00PM', '11:00-12:00AM']

data_melted = data.melt(id_vars=['Date', 'day_of_week'], 
                        value_vars=hourly_columns, 
                        var_name='hour', 
                        value_name='traffic_volume')

data_melted['hour'] = data_melted['hour'].str.extract(r'(\d{1,2}):')[0].astype(int)
data_melted.dropna(subset=['traffic_volume'], inplace=True)

X = data_melted[['hour', 'day_of_week']].values
y = data_melted['traffic_volume'].values

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=10)

# Train the Linear Regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Check if the model has been fitted properly
print("Model coefficients:", model.coef_)
print("Model intercept:", model.intercept_)

```

    Model coefficients: [  3.51621962 -20.90467424]
    Model intercept: 277.8185736052992



```python
def predict_traffic(location, hour, day_of_week):
    # Ensure the model has been trained before making predictions
    if not hasattr(model, 'coef_'):
        raise Exception("The model has not been fitted yet.")
    
    prediction = model.predict(np.array([[hour, day_of_week]]))
    return {'location': location, 'predicted_traffic': prediction[0]}

# Main function for user input
def main():
    location = input("Enter the location: ")
    hour = int(input("Enter the hour (0-23): "))
    day_of_week = int(input("Enter the day of the week (0-6 for Mon-Sun): "))

    result = predict_traffic(location, hour, day_of_week)
    print(f"Predicted traffic volume for {result['location']} at hour {hour} on day {day_of_week}: {result['predicted_traffic']}")

if __name__ == "__main__":
    main()

```

    Enter the location:  union plac
    Enter the hour (0-23):  5
    Enter the day of the week (0-6 for Mon-Sun):  3


    Predicted traffic volume for union plac at hour 5 on day 3: 232.68564895415952



```python

```
