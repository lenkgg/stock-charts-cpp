#pragma once
#include "ExpCore.h"
#include <map>
#include <set>

namespace StockCharts
{
	enum class EnStockRely
	{
		None,
		VOLV,			// ����ɽ���
		NoAdj,			// ��������Ȩ����
		UQStock,		// ����Ȩ��������������
	};
	using StockRelyData = std::map<EnStockRely, NumberCore>;

	struct IndexFormula
	{
		String					name;
		bool					sub = true;
		String					expression;
		std::map<String, int>	params;
	};

	struct IndexCore
	{
		std::vector<ExpCore>	exps;
		bool					err = false;
		String					errExpression;
		String					errWord;
	};
}
