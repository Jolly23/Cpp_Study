// ListEx1.h: interface for the CListEx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTEX1_H__AD1E834E_13C6_4434_905A_A73541280567__INCLUDED_)
#define AFX_LISTEX1_H__AD1E834E_13C6_4434_905A_A73541280567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include <algorithm>
template<typename TYPE,typename TYPE_ARG>
class CListEx:public CList<TYPE,TYPE_ARG>
{
	public:
typedef bool (*SORT_FUNC)(const TYPE& t1,const TYPE& t2);
	void Sort(SORT_FUNC byFunc)
	{
		CNode *p = m_pNodeHead, *q, *pMin;
		while(p)
		{
			q = pMin = p;	//因为p已经被赋值（头结点地址），所以p放在最后面给前两个赋值
			q = q->pNext;
			
			while(q)
			{
				if(byFunc(q->data,pMin->data))
					pMin = q;
				q = q->pNext;
			}

			if(pMin != p)
			{
				TYPE t		=	pMin->data;
				pMin->data	=	p->data;
				p->data		=	t;
			}
		
			p = p->pNext;
		}
	}
	POSITION* Sort2(SORT_FUNC byFunc)
	{
		CNode* *ps = new CNode*[this->m_nCount + 1];
		CNode* p = this->m_pNodeHead;
		
		ps[this->m_nCount + 1] = NULL;
		int i = 0;
		while(i < m_nCount)
		{
			ps[i] = p;
			p = p->pNext;
			++i;
		}					//新指针数组获取链表中每个数据地址完成！
		//sort(ps[0]->data, ps[this->m_nCount]->data, Comp);
		int m = 0, j = 0;
		i = 0;
		while(i < m_nCount)
		{
			m = i;
			j = i + 1;
			while(j < m_nCount)
			{
				if(byFunc(ps[j]->data,ps[m]->data))
					m = j;
				++j;
			}
			if(i != m)
			{
				TYPE t		=	ps[i]->data;
				ps[i]->data =	ps[m]->data;
				ps[m]->data =	t;
			}
			++i;
		}
		return (POSITION*)ps;
	}
};

#endif // !defined(AFX_LISTEX1_H__AD1E834E_13C6_4434_905A_A73541280567__INCLUDED_)
