# DayWeekOfYearJalaliCalendar
Collections Of Simple Codes For Retrieves Day Of Week In Year

#C++
 <h2>init Class:</h2>
 <p>Constructor : <code> DayOfYear(int Year, int Month, int DayInMonth, int DayInWeek);</code></p>
 <p>Receive Current Date As Input Parameter</p>
 <h3>like : </h3>
 <code>DayOfYear doy = DayOfYear(1395, 9, 1, 2);  //current date 1395/09/1 Monday</code>
 <h3>list of DayInWeek : </h3>
 <code>
 {
  "0"=>"Saturday",
  "1"=>"Sunday",
  "2"=>"Monday",
  "3"=>"Tuesday",
  "4"=>"Wednesday",
  "5"=>"Thursday",
  "6"=>"Friday"
 }
 </code>
 <br>
 <h3>Retrive Day Of Week:</h3>
 <p>fucntion: <code> int DayOfYear::getDay(int year, int month, int day) </code><br>
 Receive Date As Input Parameter For Calculate DayOfWeek
 </p>
 <code>cout&lt;&lt;doy.getDay(1397,10,4)&lt;&lt;endl;</code>
 <p>and it return <b>3</b> for result that mean 1397/10/4 is Tuesday!</p>
