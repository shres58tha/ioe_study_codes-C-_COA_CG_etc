var td,year,month,day;
function myFunction()
	{
	year=document.getElementById("year");
	year=year.options[year.selectedIndex].text;
	month=document.getElementById("month");
	month=month.options[month.selectedIndex].text;
	day=document.getElementById("day");
	day=day.options[day.selectedIndex].text;
	if(month=="Baishakh")
		{
		td=31;
		var years30=[1973,1977,2000,2004,2027,2031,2035,2058,2082,2086,2088,,2089,2090,2092,2093,2096];
		fn_years30(year,years30)
	}
	if(month=="Jestha")
		{
		td=31;
		var years32=[1972,1973,1976,1977,1980,1984,1987,1988,1991,1992,1995,1996,1999,2000,2003,2004,2007,2011,2015,2018,2019,2022,2023,2026,2027,2030,2031,2034,2035,2038,2042,2045,2046,2049,2050,2053,2054,2057,2058,2061,2065,2069,2072,2073,2076,2077,2080,2082,2085,2086,2089,2090,2093,2097,2100];
		fn_years32(year,years32)
	}
	if(month=="Ashadh")
		{
		td=32;
		var years31=[1972,1973,1976,1977,1980,1981,1984,1985,1987,1988,1989,1991,1992,1993,1995,1996,1999,2000,2003,2004,2007,2008,2011,2012,2014,2015,2016,2018,2019,2020,2022,2023,2024,2026,2027,2030,2031,2034,2035,2038,2039,2042,2043,2045,2046,2047,2049,2050,2051,2053,2054,2057,2058,2061,2062,2065,2066,2069,2070,2072,2073,2074,2076,2077,2078,2080,2082,2085,2086,2089,2090,2093,2097,2100];
		fn_years31(year,years31)
	}
	if(month=="Shrawan")
		{
		td=32;
		var years31=[1970,1971,1974,1978,1982,1986,1990,1994,1997,1998,2001,2005,2009,2013,2017,2021,2025,2028,2029,2032,2036,2040,2044,2048,2052,2055,2056,2059,2063,2067,2071,2075,2079,2083,2084,2087,2091,2094,2095,2098,2099];
		fn_years31(year,years31)
	}
	if(month=="Bhadra")
		{
		td=31;
		var years32=[1971,2029,2056];
		var years30=[2085,2088,2100];
		fn_years30(year,years30);
		fn_years32(year,years32)
	}
	if(month=="Ashwin")
		{
		td=30;
		var years31=[1970,1974,19755,1977,1978,1981,1982,1985,1986,1989,1990,1993,1994,1997,1998,2001,2005,2008,2009,2012,2013,2016,2017,2020,2021,2024,2025,2028,2032,2035,2036,2039,2040,2043,2044,2047,2048,2051,2052,2055,2059,2062,2063,2066,2067,2070,2071,2074,2075,2078,2079,2085,2087,2088,2091,2095,2098,2099,2100];
		fn_years31(year,years31)
	}
	if(month=="Kartik")
		{
		td=30;
		var years29=[1977,1981,1985,2008,2012,2016,2035,2039,2043,2062,2066,2070,2098];
		fn_years29(year,years29)
	}
	if(month=="Mangsir")
		{
		td=29;
		var years30=[1972,1973,1976,1977,1980,1981,1984,1985,1988,1991,1992,1995,1996,1999,2000,2003,2004,2007,2008,2011,2012,2015,2016,2019,2022,2023,2026,2027,2030,2031,2034,2035,2038,2039,2042,2043,2046,2049,2050,2053,2054,2057,2058,2061,2062,2065,2066,2069,2070,2073,2076,2077,2080,2081,2082,2083,2084,2085,2086,2087,2088,2089,2090,2091,2092,2093,2094,2097,2098];
		fn_years30(year,years30)
	}
	if(month=="Poush")
		{
		td=30;
		var years29=[1972,1973,1976,1977,1980,1984,1988,1991,1992,1995,1996,1999,2000,2003,2004,2007,2011,2015,2019,2022,2023,2026,2027,2030,2031,2034,2038,2042,2046,2049,2050,2053,2054,2057,2058,2061,2062,2065,2069,2073,2076,2077,2080,2081,2082,2083,2084,2085,2086,2087,2088,2089,2090,2091,2092,2093,2094,2097,2098,2099];
		fn_years29(year,years29)
	}
	if(month=="Magh")
		{
		td=29;
		var years30=[1973,1977,1992,1996,2000,2004,2019,2023,2027,2031,2050,2054,2058,2062,2077,2081,2082,2083,2084,2085,2086,2087,2088,2089,2090,2091,2092,2093,2094,2095,2097,2098,2099];
		fn_years30(year,years30)
	}
	if(month=="Falgun")
		{
		td=30;
		var years29=[1973,1977,1992,1996,2000,2004,2008,2019,2023,2027,2031,2035,2050,2054,2058,2062,2066,2077,2098];
		fn_years29(year,years29)
	}
	if(month=="Chaitra")
		{
		td=30;
		var years31=[1973,1976,1977,1980,1984,1988,1992,1996,1999,2000,2003,2004,2007,2008,2011,2015,2019,2023,2026,2027,2030,2031,2034,2035,2038,2042,2046,2050,2054,2057,2058,2061,2062,2065,2066,2069,2073,2077,2098];
		fn_years31(year,years31)
	}
	function fn_years29(year,years29)
		{
		for(var n=0;
		n<years29.length;
		n++)
			{
			if(years29[n]==year)
				{
				td=29;
				break;
				return
			}
		}
	}
	function fn_years30(year,years30)
		{
		for(var n=0;
		n<years30.length;
		n++)
			{
			if(years30[n]==year)
				{
				td=30;
				break;
				return
			}
		}
	}
	function fn_years31(year,years31)
		{
		for(var n=0;
		n<years31.length;
		n++)
			{
			if(years31[n]==year)
				{
				td=31;
				break;
				return
			}
		}
	}
	function fn_years32(year,years32)
		{
		for(var n=0;
		n<years32.length;
		n++)
			{
			if(years32[n]==year)
				{
				td=32;
				break;
				return
			}
		}
	}
	document.getElementById("day").innerHTML="";
	for(var i=1;
	i<=td;
	i++)
		{
		if(i==day)
			{
			document.getElementById("day").innerHTML+="<option selected='selected'>"+i+"</option>"
		}
		else
			{
			document.getElementById("day").innerHTML+="<option>"+i+"</option>"
		}
	}
}
myFunction();
var yeare,emonth,eday;
function myFunctionEng()
	{
	yeare=document.getElementById("yeare");
	yeare=yeare.options[yeare.selectedIndex].text;
	emonth=document.getElementById("emonth");
	emonth=emonth.options[emonth.selectedIndex].text;
	eday=document.getElementById("eday");
	eday=eday.options[eday.selectedIndex].text;
	if(emonth=="January")
		{
		emonth=1
	}
	else if(emonth=="February")
		{
		emonth=2
	}
	else if(emonth=="March")
		{
		emonth=3
	}
	else if(emonth=="April")
		{
		emonth=4
	}
	else if(emonth=="May")
		{
		emonth=5
	}
	else if(emonth=="June")
		{
		emonth=6
	}
	else if(emonth=="July")
		{
		emonth=7
	}
	else if(emonth=="August")
		{
		emonth=8
	}
	else if(emonth=="September")
		{
		emonth=9
	}
	else if(emonth=="October")
		{
		emonth=10
	}
	else if(emonth=="November")
		{
		emonth=11
	}
	else if(emonth=="December")
		{
		emonth=12
	}
	var tde=new Date(yeare,emonth,0).getDate();
	document.getElementById("eday").innerHTML="";
	for(var i=1;
	i<=tde;
	i++)
		{
		if(i==eday)
			{
			document.getElementById("eday").innerHTML+="<option selected='selected'>"+i+"</option>"
		}
		else
			{
			document.getElementById("eday").innerHTML+="<option>"+i+"</option>"
		}
	}
}
myFunctionEng();
