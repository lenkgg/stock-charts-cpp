/****************************************************************************
** MIT License
** 
** Author   : xiaofeng.zhu
** Support  : zxffffffff@outlook.com, 1337328542@qq.com
** 
****************************************************************************/
#pragma once
#include "../../Core/NumberCore.h"
#include "../../Core/Painter.h"

namespace StockCharts
{
    enum class EnKLineType
    {
        CandleStickHollow,  // ����ͼ�����ģ�
        CandleStick,        // ����ͼ
        BAR,                // ������
        CloseLine,          // ���̼���
    };

    enum class EnCoordinateType
    {
        Linear,             // �Ȳ�
        Proportional,       // �ȱ�
        Percentage,         // �ٷֱ�
        LogLinear,          // �Ȳ������
        LogProportional,    // �ȱȣ�������
        LogPercentage,      // �ٷֱȣ�������
    };

    enum class EnXAxisType
    {
        yyyyMMdd_HHmm,
        yyyyMMdd,
        yyyyMM,
        yyyy,
    };

    struct ChartProps
    {
        EnKLineType klineType = EnKLineType::CandleStick;

        EnCoordinateType coordinateType = EnCoordinateType::Linear;

        // border
        Real xAxisHeight = 30;
        Real ylAxisWidth = 50;
        Real yrAxisWidth = 50;

        // padding
        Real topPadding = 10;
        Real btmPadding = 10;
        Real leftPadding = 10;
        Real rightPadding = 10;

        // stick
        Real nodeWidth = 7;
        Real stickWidth = 5;

        // axis
        Pen axisLineStyle = Color(0, 0, 0);
        Pen axisGridStyle = Color(150, 150, 150);
        Pen crossLineStyle = Pen(Color(100, 100, 100), 1, LineType::DashLine);
        Pen crossTextBGStyle = Color(200, 200, 200);

        // x-axis
        EnXAxisType xAxisType = EnXAxisType::yyyyMMdd;
        EnXAxisType xAxisHoverType = EnXAxisType::yyyyMMdd_HHmm;
        Font xAxisTextFont = Font(Color(0, 0, 0), 12, PaintDirection::Center);

        // y-axis
        Real yAxisGridStep = 26;
        Font ylAxisTextFont = Font(Color(0, 0, 0), 12, PaintDirection::CenterRight);
        Font yrAxisTextFont = Font(Color(0, 0, 0), 12, PaintDirection::CenterLeft);
        Font ylAxisHoverTextFont = Font(Color(50, 0, 0), 12, PaintDirection::CenterRight);
        Font yrAxisHoverTextFont = Font(Color(50, 0, 0), 12, PaintDirection::CenterLeft);

        // stock
        int precision = 2;
    };

    struct ChartContext
    {
        ChartProps props;

        // [0] content
        Rect rectView;
        Rect rectXAxis;
        Rect rectYLAxis;
        Rect rectYRAxis;
        Rect rectChart;
        Rect rectInnerChart;

        // [1] x
        int viewCount = 0;
        int endIndex = 0; // lastIndex = (endIndex - 1)
        int beginIndex = 0; // = (endIndex - viewCount)

        // [2] y
        Number minPrice = NumberNull;
        Number maxPrice = NumberNull;

        // mouse event
        Point pointHover;
        int hoverIndex = -1;
        Number hoverPrice = NumberNull;
    };
}

