int Select(int a[], int start,int end,int k) {
	while(i <= end){//对数组进行分组
		int iend = i + 4;
		if (iend >= end) {
			iend = end;
		}
		quickSort(a, i, iend);
		s[m] = a[(i + iend) / 2];//找出每组中位数
		m++;
		i = iend+1;
	}
	quickSort(s, 0, m - 1);//对中位数进行排序
	int mid = s[m / 2];
	int al[MAX], ar[MAX];
	int count_al = 0, count_ar = 0;
	for (int j = start; j <= end; j++)//通过m*，将数组分为两部分
	{
		if (a[j]<mid)
		{
			al[count_al++] = a[j];
		}
		else if (a[j] > mid)
		{
			ar[count_ar++] = a[j];
		}
	}
	if (k==count_al+1)
	{
		return mid;
	}
	else if (k<= count_al)
	{
		return Select(al, 0, count_al - 1, k);
	}
	else
	{
		return Select(ar, 0, count_ar - 1, k - count_al-1);
	}
}
