#ifndef LUNASVG_H
#define LUNASVG_H


#include <memory>
#include <string>
#include <fstream>
#include <cstring>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <limits>
#include <algorithm>
#include <vector>
#include <array>

 


//#if defined(_MSC_VER) && defined(LUNASVG_SHARED)
//#ifdef LUNASVG_EXPORT
//#define LUNASVG_API __declspec(dllexport)
//#else
//#define LUNASVG_API __declspec(dllimport)
//#endif
//#else
#define LUNASVG_API
//#endif

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


#include "plutovg.h"

//namespace lunasvg {


    //class LayoutClipPath;
    class Color;
    class LayoutContainer;
    class LayoutContext;
    class ParseDocument;
    //class LayoutSymbol;
    class Length;

    class SVGElement;
    class Node;
    //class PatternElement;
    class Point;
    class LayoutMask;
    class RenderState;
    //class LayoutBreaker;



    enum class LayoutId
    {
        Symbol,
        Group,
        Shape,
        Mask,
        ClipPath,
        Marker,
        LinearGradient,
        RadialGradient,
        Pattern,
        SolidColor
    };


    enum class RenderMode
    {
        Display,
        Clipping
    };

    static const std::string EmptyString;
    static const std::string InheritString{ "inherit" };

    using GradientStop = std::pair<double, Color>;
    using GradientStops = std::vector<GradientStop>;
    using NodeList = std::list<std::unique_ptr<Node>>;
    using DashArray = std::vector<double>;
    using LengthList = std::vector<Length>;
    using PointList = std::vector<Point>;

    struct DashData
    {
        DashArray array;
        double offset{0.0};
    };

    enum class TextureType
    {
        Plain,
        Tiled
    };

    enum class BlendMode
    {
        Src,
        Src_Over,
        Dst_In,
        Dst_Out
    };


    enum class ElementId
    {
        Unknown = 0,
        //Star,
        Circle,
        //ClipPath,
        //Defs,
        Ellipse,
        G,
        Line,
        //LinearGradient,
        Marker,
        Mask,
        Path,
        //Pattern,
        //Polygon,
        //Polyline,
        //RadialGradient,
        Rect,
        SolidColor,
        Stop,
        Style,
        Svg,
        //Symbol,
        //Use
    };

    enum class PropertyId
    {
        Unknown = 0,
        Class,
        Clip_Path,
        Clip_Rule,
        ClipPathUnits,
        Color,
        Cx,
        Cy,
        D,
        Display,
        Fill,
        Fill_Opacity,
        Fill_Rule,
        Fx,
        Fy,
        GradientTransform,
        GradientUnits,
        Height,
        Href,
        Id,
        Marker_End,
        Marker_Mid,
        Marker_Start,
        MarkerHeight,
        MarkerUnits,
        MarkerWidth,
        Mask,
        MaskContentUnits,
        MaskUnits,
        Offset,
        Opacity,
        Orient,
        Overflow,
        PatternContentUnits,
        PatternTransform,
        PatternUnits,
        Points,
        PreserveAspectRatio,
        R,
        RefX,
        RefY,
        Rx,
        Ry,
        Solid_Color,
        Solid_Opacity,
        SpreadMethod,
        Stop_Color,
        Stop_Opacity,
        Stroke,
        Stroke_Dasharray,
        Stroke_Dashoffset,
        Stroke_Linecap,
        Stroke_Linejoin,
        Stroke_Miterlimit,
        Stroke_Opacity,
        Stroke_Width,
        Style,
        Transform,
        ViewBox,
        Visibility,
        Width,
        X,
        X1,
        X2,
        Y,
        Y1,
        Y2
    };

    struct Property
    {
        PropertyId id;
        std::string value;
        int specificity;
    };

    class PropertyList
    {
    public:
        PropertyList() = default;

        void set(PropertyId id, const std::string& value, int specificity)
        {
            auto property = get(id);
            if (property == nullptr)
            {
                Property property{ id, value, specificity };
                m_properties.push_back(std::move(property));
                return;
            }

            if (property->specificity > specificity)
                return;

            property->specificity = specificity;
            property->value = value;
        }
        Property* get(PropertyId id) const
        {
            auto data = m_properties.data();
            auto end = data + m_properties.size();
            while (data < end)
            {
                if (data->id == id)
                    return const_cast<Property*>(data);
                ++data;
            }

            return nullptr;
        }
        //    void add(const Property& property)///
        //    {
        //        set(property.id, property.value, property.specificity);
        //    }
        //    void add(const PropertyList& properties)///
        //    {
        //        auto it = properties.m_properties.begin();
        //        auto end = properties.m_properties.end();
        //        for(;it != end;++it)
        //            add(*it);
        //    }

    private:
        std::vector<Property> m_properties;
    };


    enum class Display
    {
        Inline,
        None
    };

    enum class Visibility
    {
        Visible,
        Hidden
    };

    enum class Overflow
    {
        Visible,
        Hidden
    };

    enum class LineCap
    {
        Butt,
        Round,
        Square
    };

    enum class LineJoin
    {
        Miter,
        Round,
        Bevel
    };

    enum class WindRule
    {
        NonZero,
        EvenOdd
    };

    enum class Units
    {
        UserSpaceOnUse,
        ObjectBoundingBox
    };

    enum class SpreadMethod
    {
        Pad,
        Reflect,
        Repeat
    };

    enum class MarkerUnits
    {
        StrokeWidth,
        UserSpaceOnUse
    };

    static const double pi = 3.14159265358979323846;
    static const double kappa = 0.55228474983079339840;
    static const double dpi = 96.0;
    static const double sqrt2 = 1.41421356237309504880;


    class Color
    {
    public:
        Color() = default;
        Color(double r, double g, double b, double a = 1)
            : r(r), g(g), b(b), a(a)
        {
        }

        bool isNone() const { return  a == 0.0; }

        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Transparent;

    public:
        double r{ 0 };
        double g{ 0 };
        double b{ 0 };
        double a{ 1 };
    };

    const Color Color::Black{ 0, 0, 0, 1 };
    const Color Color::White{ 1, 1, 1, 1 };
    const Color Color::Red{ 1, 0, 0, 1 };
    const Color Color::Green{ 0, 1, 0, 1 };
    const Color Color::Blue{ 0, 0, 1, 1 };
    const Color Color::Yellow{ 1, 1, 0, 1 };
    const Color Color::Transparent{ 0, 0, 0, 0 };

    class Paint
    {
    public:
        Paint() = default;
        Paint(const Color& color)
            : m_color(color)
        {
        }
        Paint(const std::string& ref, const Color& color)
            : m_ref(ref), m_color(color)
        {
        }

        const Color& color() const { return m_color; }
        const std::string& ref() const { return m_ref; }
        bool isNone() const { return m_ref.empty() && m_color.isNone(); }

    public:
        Color m_color{ Color::Transparent };
        std::string m_ref;
    };

    class Point
    {
    public:
        Point() = default;
        Point(double x, double y)
            : x(x), y(y)
        {
        }

    public:
        double x{ 0 };
        double y{ 0 };
    };


    class Rect
    {
    public:
        Rect() = default;
        Rect(double x, double y, double w, double h)
            : x(x), y(y), w(w), h(h)
        {
        }

        //    Rect operator&(const Rect& rect) const
        //    {
        //        if(!rect.valid())
        //            return *this;

        //        if(!valid())
        //            return rect;

        //        auto l = std::max(x, rect.x);
        //        auto t = std::max(y, rect.y);
        //        auto r = std::min(x + w, rect.x + rect.w);
        //        auto b = std::min(y + h, rect.y + rect.h);

        //        return Rect{l, t, r-l, b-t};
        //    }
        //    Rect operator|(const Rect& rect) const
        //    {
        //        if(!rect.valid())
        //            return *this;

        //        if(!valid())
        //            return rect;

        //        auto l = std::min(x, rect.x);
        //        auto t = std::min(y, rect.y);
        //        auto r = std::max(x + w, rect.x + rect.w);
        //        auto b = std::max(y + h, rect.y + rect.h);

        //        return Rect{l, t, r-l, b-t};
        //    }

        //    Rect& intersect(const Rect& rect)
        //    {
        //        *this = *this & rect;
        //        return *this;
        //    }
        //    Rect& unite(const Rect& rect)
        //    {
        //        *this = *this | rect;
        //        return *this;
        //    }

        bool empty() const { return w <= 0.0 || h <= 0.0; }
        bool valid() const { return w >= 0.0 && h >= 0.0; }

        static const Rect Empty;
        static const Rect Invalid;

    public:
        double x{ 0 };
        double y{ 0 };
        double w{ 0 };
        double h{ 0 };
    };

    const Rect Rect::Empty{ 0, 0, 0, 0 };
    const Rect Rect::Invalid{ 0, 0, -1, -1 };

    class Transform
    {
    public:
        Transform() = default;
        Transform(double m00, double m10, double m01, double m11, double m02, double m12)
            : m00(m00), m10(m10), m01(m01), m11(m11), m02(m02), m12(m12)
        {
        }

        Transform inverted() const
        {
            double det = (this->m00 * this->m11 - this->m10 * this->m01);
            if (det == 0.0)
                return Transform{};

            double inv_det = 1.0 / det;
            double m00 = this->m00 * inv_det;
            double m10 = this->m10 * inv_det;
            double m01 = this->m01 * inv_det;
            double m11 = this->m11 * inv_det;
            double m02 = (this->m01 * this->m12 - this->m11 * this->m02) * inv_det;
            double m12 = (this->m10 * this->m02 - this->m00 * this->m12) * inv_det;

            return Transform{ m11, -m10, -m01, m00, m02, m12 };
        }
        Transform operator*(const Transform& transform) const
        {
            double m00 = this->m00 * transform.m00 + this->m10 * transform.m01;
            double m10 = this->m00 * transform.m10 + this->m10 * transform.m11;
            double m01 = this->m01 * transform.m00 + this->m11 * transform.m01;
            double m11 = this->m01 * transform.m10 + this->m11 * transform.m11;
            double m02 = this->m02 * transform.m00 + this->m12 * transform.m01 + transform.m02;
            double m12 = this->m02 * transform.m10 + this->m12 * transform.m11 + transform.m12;

            return Transform{ m00, m10, m01, m11, m02, m12 };
        }
            Transform& operator*=(const Transform& transform)///
            {
                *this = *this * transform;
                return *this;
            }


            Transform& premultiply(const Transform& transform)///
            {
                *this = transform * *this;
                return *this;
            }
            Transform& postmultiply(const Transform& transform)///
            {
                *this = *this * transform;
                return *this;
            }
            Transform& rotate(double angle)///
            {
                *this = rotated(angle) * *this;
                return *this;
            }
            Transform& rotate(double angle, double cx, double cy)///
            {
                *this = rotated(angle, cx, cy) * *this;
                return *this;
            }
            Transform& scale(double sx, double sy)///
            {
                *this = scaled(sx, sy) * *this;
                return *this;
            }
            Transform& shear(double shx, double shy)///
            {
                *this = sheared(shx, shy) * *this;
                return *this;
            }
            Transform& translate(double tx, double ty)///
            {
                *this = translated(tx, ty) * *this;
                return *this;
            }
            Transform& transform(double m00, double m10, double m01, double m11, double m02, double m12)
            {
                *this = Transform{m00, m10, m01, m11, m02, m12} * *this;
                return *this;
            }
            Transform& identity()
            {
                *this = Transform{1, 0, 0, 1, 0, 0};
                return *this;
            }
            Transform& invert()
            {
                *this = inverted();
                return *this;
            }

            void map(double x, double y, double* _x, double* _y) const
            {
                *_x = x * m00 + y * m01 + m02;
                *_y = x * m10 + y * m11 + m12;
            }
            Point map(double x, double y) const
            {
                map(x, y, &x, &y);
                return Point{x, y};
            }
            Point map(const Point& point) const
            {
                return map(point.x, point.y);
            }
            Rect map(const Rect& rect) const
            {
                if(!rect.valid())
                    return Rect::Invalid;

                auto x1 = rect.x;
                auto y1 = rect.y;
                auto x2 = rect.x + rect.w;
                auto y2 = rect.y + rect.h;

                const Point p[] = {
                    map(x1, y1), map(x2, y1),
                    map(x2, y2), map(x1, y2)
                };

                auto l = p[0].x;
                auto t = p[0].y;
                auto r = p[0].x;
                auto b = p[0].y;

                for(int i = 1;i < 4;i++)
                {
                    if(p[i].x < l) l = p[i].x;
                    if(p[i].x > r) r = p[i].x;
                    if(p[i].y < t) t = p[i].y;
                    if(p[i].y > b) b = p[i].y;
                }

                return Rect{l, t, r-l, b-t};
            }

            static Transform rotated(double angle)///
            {
                auto c = std::cos(angle * pi / 180.0);
                auto s = std::sin(angle * pi / 180.0);

                return Transform{c, s, -s, c, 0, 0};
            }
            static Transform rotated(double angle, double cx, double cy)///
            {
                auto c = std::cos(angle * pi / 180.0);
                auto s = std::sin(angle * pi / 180.0);

                auto x = cx * (1 - c) + cy * s;
                auto y = cy * (1 - c) - cx * s;

                return Transform{c, s, -s, c, x, y};
            }
            static Transform scaled(double sx, double sy)///
            {
                return Transform{sx, 0, 0, sy, 0, 0};
            }
            static Transform sheared(double shx, double shy)///
            {
                auto x = std::tan(shx * pi / 180.0);
                auto y = std::tan(shy * pi / 180.0);

                return Transform{1, y, x, 1, 0, 0};
            }
        static Transform translated(double tx, double ty)
        {
            return Transform{ 1, 0, 0, 1, tx, ty };
        }

    public:
        double m00{ 1 };
        double m10{ 0 };
        double m01{ 0 };
        double m11{ 1 };
        double m02{ 0 };
        double m12{ 0 };
    };

    enum class PathCommand
    {
        MoveTo,
        LineTo,
        CubicTo,
        Close
    };

    class Path
    {
    public:
        Path() = default;

        void moveTo(double x, double y)
        {
            m_commands.push_back(PathCommand::MoveTo);
            m_points.emplace_back(x, y);
        }
        void lineTo(double x, double y)
        {
            m_commands.push_back(PathCommand::LineTo);
            m_points.emplace_back(x, y);
        }
        void cubicTo(double x1, double y1, double x2, double y2, double x3, double y3)
        {
            m_commands.push_back(PathCommand::CubicTo);
            m_points.emplace_back(x1, y1);
            m_points.emplace_back(x2, y2);
            m_points.emplace_back(x3, y3);
        }
        void close()
        {
            if (m_commands.empty())
                return;

            if (m_commands.back() == PathCommand::Close)
                return;

            m_commands.push_back(PathCommand::Close);
        }
        void reset()
        {
            m_commands.clear();
            m_points.clear();
        }
        bool empty() const
        {
            return m_commands.empty();
        }

        //    void quadTo(double cx, double cy, double x1, double y1, double x2, double y2)
        //    {
        //        auto cx1 = 2.0 / 3.0 * x1 + 1.0 / 3.0 * cx;
        //        auto cy1 = 2.0 / 3.0 * y1 + 1.0 / 3.0 * cy;
        //        auto cx2 = 2.0 / 3.0 * x1 + 1.0 / 3.0 * x2;
        //        auto cy2 = 2.0 / 3.0 * y1 + 1.0 / 3.0 * y2;
        //        cubicTo(cx1, cy1, cx2, cy2, x2, y2);
        //    }
        //    void arcTo(double cx, double cy, double rx, double ry, double xAxisRotation, bool largeArcFlag, bool sweepFlag, double x, double y)
        //    {
        //        rx = std::fabs(rx);
        //        ry = std::fabs(ry);

        //        auto sin_th = std::sin(xAxisRotation * pi / 180.0);
        //        auto cos_th = std::cos(xAxisRotation * pi / 180.0);

        //        auto dx = (cx - x) / 2.0;
        //        auto dy = (cy - y) / 2.0;
        //        auto dx1 =  cos_th * dx + sin_th * dy;
        //        auto dy1 = -sin_th * dx + cos_th * dy;
        //        auto Pr1 = rx * rx;
        //        auto Pr2 = ry * ry;
        //        auto Px = dx1 * dx1;
        //        auto Py = dy1 * dy1;
        //        auto check = Px / Pr1 + Py / Pr2;
        //        if(check > 1)
        //        {
        //            rx = rx * std::sqrt(check);
        //            ry = ry * std::sqrt(check);
        //        }

        //        auto a00 =  cos_th / rx;
        //        auto a01 =  sin_th / rx;
        //        auto a10 = -sin_th / ry;
        //        auto a11 =  cos_th / ry;
        //        auto x0 = a00 * cx + a01 * cy;
        //        auto y0 = a10 * cx + a11 * cy;
        //        auto x1 = a00 * x + a01 * y;
        //        auto y1 = a10 * x + a11 * y;
        //        auto d = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
        //        auto sfactor_sq = 1.0 / d - 0.25;
        //        if(sfactor_sq < 0) sfactor_sq = 0;
        //        auto sfactor = std::sqrt(sfactor_sq);
        //        if(sweepFlag == largeArcFlag) sfactor = -sfactor;
        //        auto xc = 0.5 * (x0 + x1) - sfactor * (y1 - y0);
        //        auto yc = 0.5 * (y0 + y1) + sfactor * (x1 - x0);

        //        auto th0 = std::atan2(y0 - yc, x0 - xc);
        //        auto th1 = std::atan2(y1 - yc, x1 - xc);

        //        double th_arc = th1 - th0;
        //        if(th_arc < 0.0 && sweepFlag)
        //            th_arc += 2.0 * pi;
        //        else if(th_arc > 0.0 && !sweepFlag)
        //            th_arc -= 2.0 * pi;

        //        auto n_segs = static_cast<int>(std::ceil(std::fabs(th_arc / (pi * 0.5 + 0.001))));
        //        for(int i = 0;i < n_segs;i++)
        //        {
        //            auto th2 = th0 + i * th_arc / n_segs;
        //            auto th3 = th0 + (i + 1) * th_arc / n_segs;

        //            auto a00 =  cos_th * rx;
        //            auto a01 = -sin_th * ry;
        //            auto a10 =  sin_th * rx;
        //            auto a11 =  cos_th * ry;

        //            auto thHalf = 0.5 * (th3 - th2);
        //            auto t = (8.0 / 3.0) * std::sin(thHalf * 0.5) * std::sin(thHalf * 0.5) / std::sin(thHalf);
        //            auto x1 = xc + std::cos(th2) - t * std::sin(th2);
        //            auto y1 = yc + std::sin(th2) + t * std::cos(th2);
        //            auto x3 = xc + std::cos(th3);
        //            auto y3 = yc + std::sin(th3);
        //            auto x2 = x3 + t * std::sin(th3);
        //            auto y2 = y3 - t * std::cos(th3);

        //            auto cx1 = a00 * x1 + a01 * y1;
        //            auto cy1 = a10 * x1 + a11 * y1;
        //            auto cx2 = a00 * x2 + a01 * y2;
        //            auto cy2 = a10 * x2 + a11 * y2;
        //            auto cx3 = a00 * x3 + a01 * y3;
        //            auto cy3 = a10 * x3 + a11 * y3;
        //            cubicTo(cx1, cy1, cx2, cy2, cx3, cy3);
        //        }
        //    }

        void ellipse(double cx, double cy, double rx, double ry)
        {
            auto left = cx - rx;
            auto top = cy - ry;
            auto right = cx + rx;
            auto bottom = cy + ry;

            auto cpx = rx * kappa;
            auto cpy = ry * kappa;

            moveTo(cx, top);
            cubicTo(cx + cpx, top, right, cy - cpy, right, cy);
            cubicTo(right, cy + cpy, cx + cpx, bottom, cx, bottom);
            cubicTo(cx - cpx, bottom, left, cy + cpy, left, cy);
            cubicTo(left, cy - cpy, cx - cpx, top, cx, top);
            close();
        }
        void rect(double x, double y, double w, double h, double rx, double ry)
        {
            rx = std::min(rx, w * 0.5);
            ry = std::min(ry, h * 0.5);

            auto right = x + w;
            auto bottom = y + h;

            if (rx == 0.0 && ry == 0.0)
            {
                moveTo(x, y);
                lineTo(right, y);
                lineTo(right, bottom);
                lineTo(x, bottom);
                lineTo(x, y);
                close();
            }
            else
            {
                double cpx = rx * kappa;
                double cpy = ry * kappa;
                moveTo(x, y + ry);
                cubicTo(x, y + ry - cpy, x + rx - cpx, y, x + rx, y);
                lineTo(right - rx, y);
                cubicTo(right - rx + cpx, y, right, y + ry - cpy, right, y + ry);
                lineTo(right, bottom - ry);
                cubicTo(right, bottom - ry + cpy, right - rx + cpx, bottom, right - rx, bottom);
                lineTo(x + rx, bottom);
                cubicTo(x + rx - cpx, bottom, x, bottom - ry + cpy, x, bottom - ry);
                lineTo(x, y + ry);
                close();
            }
        }

        //    Rect box() const
        //    {
        //        if(m_points.empty())
        //            return Rect{};

        //        auto l = m_points[0].x;
        //        auto t = m_points[0].y;
        //        auto r = m_points[0].x;
        //        auto b = m_points[0].y;

        //        for(std::size_t i = 1;i < m_points.size();i++)
        //        {
        //            if(m_points[i].x < l) l = m_points[i].x;
        //            if(m_points[i].x > r) r = m_points[i].x;
        //            if(m_points[i].y < t) t = m_points[i].y;
        //            if(m_points[i].y > b) b = m_points[i].y;
        //        }

        //        return Rect{l, t, r-l, b-t};
        //    }

        const std::vector<PathCommand>& commands() const { return m_commands; }
        const std::vector<Point>& points() const { return m_points; }

    private:
        std::vector<PathCommand> m_commands;
        std::vector<Point> m_points;
    };

    class PathIterator
    {
    public:
        PathIterator(const Path& path)
            : m_commands(path.commands()),
            m_points(path.points().data())
        {
        }

        PathCommand currentSegment(std::array<Point, 3>& points) const
        {
            auto command = m_commands[m_index];
            switch (command) {
            case PathCommand::MoveTo:
                points[0] = m_points[0];
                m_startPoint = points[0];
                break;
            case PathCommand::LineTo:
                points[0] = m_points[0];
                break;
            case PathCommand::CubicTo:
                points[0] = m_points[0];
                points[1] = m_points[1];
                points[2] = m_points[2];
                break;
            case PathCommand::Close:
                points[0] = m_startPoint;
                break;
            }

            return command;
        }
        bool isDone() const
        {
            return (m_index >= m_commands.size());
        }
        void next()
        {
            switch (m_commands[m_index]) {
            case PathCommand::MoveTo:
            case PathCommand::LineTo:
                m_points += 1;
                break;
            case PathCommand::CubicTo:
                m_points += 3;
                break;
            default:
                break;
            }

            m_index += 1;
        }

    private:
        mutable Point m_startPoint;
        const std::vector<PathCommand>& m_commands;
        const Point* m_points{ nullptr };
        unsigned int m_index{ 0 };
    };

    enum class LengthUnits
    {
        Unknown,
        Number,
        Px,
        Pt,
        Pc,
        In,
        Cm,
        Mm,
        Ex,
        Em,
        Percent
    };

    enum LengthMode
    {
        Width,
        Height,
        Both
    };




    class Element;
    class StyledElement;

    class Node
    {
    public:
        Node() = default;
        virtual ~Node() = default;

        //virtual bool isText() const { return false; }
        virtual bool isPaint() const { return false; }
    //    virtual bool isGeometry() const { return false; }
        virtual void layout(LayoutContext*, LayoutContainer*) const
        {
        }
        virtual std::unique_ptr<Node> clone() const = 0;

    public:
        Element* parent = nullptr;
    };

    //class TextNode : public Node
    //{
    //public:
    //    TextNode() = default;

    //    bool isText() const { return true; }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        auto node = make_unique<TextNode>();
    //        node->text = text;
    //        return std::move(node);
    //    }

    //public:
    //    std::string text;
    //};

    class Element : public Node
    {
    public:
        Element(ElementId id)
            : id(id)
        {
        }

        void set(PropertyId id, const std::string& value, int specificity)
        {
            properties.set(id, value, specificity);
        }
        const std::string& get(PropertyId id) const
        {
            auto property = properties.get(id);
            if (property == nullptr)
                return EmptyString;

            return property->value;
        }
        const std::string& find(PropertyId id) const
        {
            auto element = this;
            do {
                auto& value = element->get(id);
                if (!value.empty() && value != InheritString)
                    return value;
                element = element->parent;
            } while (element);

            return EmptyString;
        }
        bool has(PropertyId id) const
        {
            return properties.get(id);
        }

        //    Element* previousSibling() const///
        //    {
        //        if(parent == nullptr)
        //            return nullptr;

        //        Element* element = nullptr;
        //        auto it = parent->children.begin();
        //        auto end = parent->children.end();
        //        for(;it != end;++it)
        //        {
        //            auto node = it->get();
        //            if(node->isText())
        //                continue;

        //            if(node == this)
        //                return element;
        //            element = static_cast<Element*>(node);
        //        }

        //        return nullptr;
        //    }
        //    Element* nextSibling() const///
        //    {
        //        if(parent == nullptr)
        //            return nullptr;

        //        Element* element = nullptr;
        //        auto it = parent->children.rbegin();
        //        auto end = parent->children.rend();
        //        for(;it != end;++it)
        //        {
        //            auto node = it->get();
        //            if(node->isText())
        //                continue;

        //            if(node == this)
        //                return element;
        //            element = static_cast<Element*>(node);
        //        }

        //        return nullptr;
        //    }
        Node* addChild(std::unique_ptr<Node> child)
        {
            child->parent = this;
            children.push_back(std::move(child));
            return &*children.back();
        }
        void layoutChildren(LayoutContext* context, LayoutContainer* current) const
        {
            for (auto& child : children)
                child->layout(context, current);
        }
        //    Rect currentViewport() const;///

        //    template<typename T>
        //    void transverse(T callback)///
        //    {
        //        if(callback(this))
        //            return;

        //        for(auto& child : children)
        //        {
        //            if(child->isText())
        //            {
        //                if(callback(child.get()))
        //                    return;
        //                continue;
        //            }

        //            auto element = static_cast<Element*>(child.get());
        //            element->transverse(callback);
        //        }
        //    }

            template<typename T>
            std::unique_ptr<T> cloneElement() const///
            {
                auto element = make_unique<T>();
                element->properties = properties;
                for(auto& child : children)
                    element->addChild(child->clone());
                return element;
            }

    public:
        ElementId id;
        NodeList children;
        PropertyList properties;
    };


    class Length
    {
    public:
        Length() = default;
        Length(double value)
            : m_value(value)
        {
        }
        Length(double value, LengthUnits units)
            : m_value(value), m_units(units)
        {
        }

        double value(double max) const
        {
            switch (m_units) {
            case LengthUnits::Number:
            case LengthUnits::Px:
                return m_value;
            case LengthUnits::In:
                return m_value * dpi;
            case LengthUnits::Cm:
                return m_value * dpi / 2.54;
            case LengthUnits::Mm:
                return m_value * dpi / 25.4;
            case LengthUnits::Pt:
                return m_value * dpi / 72.0;
            case LengthUnits::Pc:
                return m_value * dpi / 6.0;
            case LengthUnits::Percent:
                return m_value * max / 100.0;
            default:
                break;
            }

            return 0.0;
        }
        double value(const Element* element, LengthMode mode) const
        {
            if (m_units == LengthUnits::Percent)
            {
                printf("m_units == LengthUnits::Percent");
                //auto viewport = element->currentViewport();
               //auto w = viewport.w;
                //auto h = viewport.h;
                ///auto max = (mode == LengthMode::Width) ? w : (mode == LengthMode::Height) ? h : std::sqrt(w*w+h*h) / sqrt2;
                return 0;//m_value * max / 100.0;
            }

            return value(1.0);
        }

        bool isValid() const { return  m_units != LengthUnits::Unknown; }
        bool isZero() const { return m_value == 0.0; }
        bool isRelative() const { return m_units == LengthUnits::Percent || m_units == LengthUnits::Em || m_units == LengthUnits::Ex; }

        static const Length Unknown;
        static const Length Zero;
        static const Length One;
        static const Length ThreePercent;
        static const Length HundredPercent;
        static const Length FiftyPercent;
        static const Length OneTwentyPercent;
        static const Length MinusTenPercent;

    private:
        double m_value{ 0 };
        LengthUnits m_units{ LengthUnits::Px };
    };


    const Length Length::Unknown{ 0, LengthUnits::Unknown };
    const Length Length::Zero{ 0, LengthUnits::Number };
    const Length Length::One{ 1, LengthUnits::Number };
    const Length Length::ThreePercent{ 3, LengthUnits::Percent };
    const Length Length::HundredPercent{ 100, LengthUnits::Percent };
    const Length Length::FiftyPercent{ 50, LengthUnits::Percent };
    const Length Length::OneTwentyPercent{ 120, LengthUnits::Percent };
    const Length Length::MinusTenPercent{ -10, LengthUnits::Percent };



    class LengthContext
    {
    public:
        LengthContext(const Element* element)
            : m_element(element)
        {
        }
        LengthContext(const Element* element, Units units)
            : m_element(element), m_units(units)
        {
        }

        double valueForLength(const Length& length, LengthMode mode) const
        {
            if (m_units == Units::ObjectBoundingBox)
                return length.value(1.0);
            return length.value(m_element, mode);
        }

    private:
        const Element* m_element{ nullptr };
        Units m_units{ Units::UserSpaceOnUse };
    };

    enum class Align
    {
        None,
        xMinYMin,
        xMidYMin,
        xMaxYMin,
        xMinYMid,
        xMidYMid,
        xMaxYMid,
        xMinYMax,
        xMidYMax,
        xMaxYMax
    };

    enum class MeetOrSlice
    {
        Meet,
        Slice
    };

    class PreserveAspectRatio
    {
    public:
        PreserveAspectRatio() = default;
        PreserveAspectRatio(Align align, MeetOrSlice scale)
            : m_align(align), m_scale(scale)
        {
        }

        Transform getMatrix(double width, double height, const Rect& viewBox) const
        {
            if (viewBox.empty())
                return Transform{};

            auto xscale = width / viewBox.w;
            auto yscale = height / viewBox.h;
            if (m_align == Align::None)
            {
                auto xoffset = -viewBox.x * xscale;
                auto yoffset = -viewBox.y * yscale;
                return Transform{ xscale, 0, 0, yscale, xoffset, yoffset };
            }

            auto scale = (m_scale == MeetOrSlice::Meet) ? std::min(xscale, yscale) : std::max(xscale, yscale);
            auto viewWidth = viewBox.w * scale;
            auto viewHeight = viewBox.h * scale;

            auto xoffset = -viewBox.x * scale;
            auto yoffset = -viewBox.y * scale;

            switch (m_align) {
            case Align::xMidYMin:
            case Align::xMidYMid:
            case Align::xMidYMax:
                xoffset += (width - viewWidth) * 0.5;
                break;
            case Align::xMaxYMin:
            case Align::xMaxYMid:
            case Align::xMaxYMax:
                xoffset += (width - viewWidth);
                break;
            default:
                break;
            }

            switch (m_align) {
            case Align::xMinYMid:
            case Align::xMidYMid:
            case Align::xMaxYMid:
                yoffset += (height - viewHeight) * 0.5;
                break;
            case Align::xMinYMax:
            case Align::xMidYMax:
            case Align::xMaxYMax:
                yoffset += (height - viewHeight);
                break;
            default:
                break;
            }

            return Transform{ scale, 0, 0, scale, xoffset, yoffset };
        }
            Rect getClip(double width, double height, const Rect& viewBox) const
            {
                if(viewBox.empty())
                    return Rect{0, 0, width, height};

                return viewBox;
            }

        Align align() const { return m_align; }
        MeetOrSlice scale() const { return m_scale; }

    private:
        Align m_align{ Align::xMidYMid };
        MeetOrSlice m_scale{ MeetOrSlice::Meet };
    };

    enum class MarkerOrient
    {
        Auto,
        Angle
    };

    class Angle///
    {
    public:
        Angle() = default;
        Angle(MarkerOrient type)
            : m_type(type)
        {
        }
        Angle(double value, MarkerOrient type)
            : m_value(value), m_type(type)
        {
        }

        double value() const { return m_value; }
        MarkerOrient type() const { return m_type; }

    private:
        double m_value{0};
        MarkerOrient m_type{MarkerOrient::Angle};
    };


#define IS_ALPHA(c) ((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z')
#define IS_NUM(c) ((c) >= '0' && (c) <= '9')
#define IS_WS(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')

    namespace Utils {

        inline const char* rtrim(const char* start, const char* end)
        {
            while (end > start && IS_WS(end[-1]))
                --end;

            return end;
        }

        inline const char* ltrim(const char* start, const char* end)
        {
            while (start < end && IS_WS(*start))
                ++start;

            return start;
        }

        inline bool skipDesc(const char*& ptr, const char* end, const char ch)
        {
            if (ptr >= end || *ptr != ch)
                return false;

            ++ptr;
            return true;
        }

        inline bool skipDesc(const char*& ptr, const char* end, const char* data)
        {
            int read = 0;
            while (data[read])
            {
                if (ptr >= end || *ptr != data[read])
                {
                    ptr -= read;
                    return false;
                }

                ++read;
                ++ptr;
            }

            return true;
        }

        inline bool skipUntil(const char*& ptr, const char* end, const char ch)
        {
            while(ptr < end && *ptr != ch)
                ++ptr;

            return ptr < end;
        }

        inline bool skipUntil(const char*& ptr, const char* end, const char* data)
        {
            while(ptr < end)
            {
                auto start = ptr;
                if(skipDesc(start, end, data))
                    break;
                ++ptr;
            }

            return ptr < end;
        }

        inline bool readUntil(const char*& ptr, const char* end, const char ch, std::string& value)///
        {
            auto start = ptr;
            if(!skipUntil(ptr, end, ch))
                return false;

            value.assign(start, ptr);
            return true;
        }

        inline bool readUntil(const char*& ptr, const char* end, const char* data, std::string& value)
        {
            auto start = ptr;
            if(!skipUntil(ptr, end, data))
                return false;

            value.assign(start, ptr);
            return true;
        }

        inline bool skipWs(const char*& ptr, const char* end)
        {
            while (ptr < end && IS_WS(*ptr))
                ++ptr;

            return ptr < end;
        }

        inline bool skipWsDelimiter(const char*& ptr, const char* end, const char delimiter)
        {
            if (ptr < end && !IS_WS(*ptr) && *ptr != delimiter)
                return false;

            if (skipWs(ptr, end))
            {
                if (ptr < end && *ptr == delimiter)
                {
                    ++ptr;
                    skipWs(ptr, end);
                }
            }

            return ptr < end;
        }

        inline bool skipWsComma(const char*& ptr, const char* end)
        {
            return skipWsDelimiter(ptr, end, ',');
        }

        inline bool isIntegralDigit(char ch, int base)
        {
            if (IS_NUM(ch))
                return ch - '0' < base;

            if (IS_ALPHA(ch))
                return (ch >= 'a' && ch < 'a' + std::min(base, 36) - 10) || (ch >= 'A' && ch < 'A' + std::min(base, 36) - 10);

            return false;
        }

        template<typename T>
        inline bool parseInteger(const char*& ptr, const char* end, T& integer, int base = 10)
        {
            bool isNegative = 0;
            T value = 0;

            static const T intMax = std::numeric_limits<T>::max();
            static const bool isSigned = std::numeric_limits<T>::is_signed;
            using signed_t = typename std::make_signed<T>::type;
            const T maxMultiplier = intMax / static_cast<T>(base);

            if (ptr < end && *ptr == '+')
                ++ptr;
            else if (ptr < end && isSigned && *ptr == '-')
            {
                ++ptr;
                isNegative = true;
            }

            if (ptr >= end || !isIntegralDigit(*ptr, base))
                return false;

            do {
                const char ch = *ptr++;
                int digitValue;
                if (IS_NUM(ch))
                    digitValue = ch - '0';
                else if (ch >= 'a')
                    digitValue = ch - 'a' + 10;
                else
                    digitValue = ch - 'A' + 10;

                if (value > maxMultiplier || (value == maxMultiplier && static_cast<T>(digitValue) > (intMax % static_cast<T>(base)) + isNegative))
                    return false;
                value = static_cast<T>(base) * value + static_cast<T>(digitValue);
            } while (ptr < end && isIntegralDigit(*ptr, base));

            if (isNegative)
                integer = -static_cast<signed_t>(value);
            else
                integer = value;

            return true;
        }

        template<typename T>
        inline bool parseNumber(const char*& ptr, const char* end, T& number)
        {
            T integer, fraction;
            int sign, expsign, exponent;

            static const T numberMax = std::numeric_limits<T>::max();
            fraction = 0;
            integer = 0;
            exponent = 0;
            sign = 1;
            expsign = 1;

            if (ptr < end && *ptr == '+')
                ++ptr;
            else if (ptr < end && *ptr == '-')
            {
                ++ptr;
                sign = -1;
            }

            if (ptr >= end || !(IS_NUM(*ptr) || *ptr == '.'))
                return false;

            if (*ptr != '.')
            {
                do {
                    integer = static_cast<T>(10) * integer + (*ptr - '0');
                    ++ptr;
                } while (ptr < end && IS_NUM(*ptr));
            }

            if (ptr < end && *ptr == '.')
            {
                ++ptr;
                if (ptr >= end || !IS_NUM(*ptr))
                    return false;

                T divisor = 1;
                do {
                    fraction = static_cast<T>(10) * fraction + (*ptr - '0');
                    divisor *= static_cast<T>(10);
                    ++ptr;
                } while (ptr < end && IS_NUM(*ptr));
                fraction /= divisor;
            }

            if (ptr < end && (*ptr == 'e' || *ptr == 'E')
                && (ptr[1] != 'x' && ptr[1] != 'm'))
            {
                ++ptr;
                if (ptr < end && *ptr == '+')
                    ++ptr;
                else if (ptr < end && *ptr == '-')
                {
                    ++ptr;
                    expsign = -1;
                }

                if (ptr >= end || !IS_NUM(*ptr))
                    return false;

                do {
                    exponent = 10 * exponent + (*ptr - '0');
                    ++ptr;
                } while (ptr < end && IS_NUM(*ptr));
            }

            number = sign * (integer + fraction);
            if (exponent)
                number *= static_cast<T>(pow(10.0, expsign * exponent));

            return number >= -numberMax && number <= numberMax;
        }

    } // namespace Utils


    static const std::map<std::string, unsigned int> colormap = {
        {"aliceblue", 0xF0F8FF},
        {"antiquewhite", 0xFAEBD7},
        {"aqua", 0x00FFFF},
        {"aquamarine", 0x7FFFD4},
        {"azure", 0xF0FFFF},
        {"beige", 0xF5F5DC},
        {"bisque", 0xFFE4C4},
        {"black", 0x000000},
        {"blanchedalmond", 0xFFEBCD},
        {"blue", 0x0000FF},
        {"blueviolet", 0x8A2BE2},
        {"brown", 0xA52A2A},
        {"burlywood", 0xDEB887},
        {"cadetblue", 0x5F9EA0},
        {"chartreuse", 0x7FFF00},
        {"chocolate", 0xD2691E},
        {"coral", 0xFF7F50},
        {"cornflowerblue", 0x6495ED},
        {"cornsilk", 0xFFF8DC},
        {"crimson", 0xDC143C},
        {"cyan", 0x00FFFF},
        {"darkblue", 0x00008B},
        {"darkcyan", 0x008B8B},
        {"darkgoldenrod", 0xB8860B},
        {"darkgray", 0xA9A9A9},
        {"darkgreen", 0x006400},
        {"darkgrey", 0xA9A9A9},
        {"darkkhaki", 0xBDB76B},
        {"darkmagenta", 0x8B008B},
        {"darkolivegreen", 0x556B2F},
        {"darkorange", 0xFF8C00},
        {"darkorchid", 0x9932CC},
        {"darkred", 0x8B0000},
        {"darksalmon", 0xE9967A},
        {"darkseagreen", 0x8FBC8F},
        {"darkslateblue", 0x483D8B},
        {"darkslategray", 0x2F4F4F},
        {"darkslategrey", 0x2F4F4F},
        {"darkturquoise", 0x00CED1},
        {"darkviolet", 0x9400D3},
        {"deeppink", 0xFF1493},
        {"deepskyblue", 0x00BFFF},
        {"dimgray", 0x696969},
        {"dimgrey", 0x696969},
        {"dodgerblue", 0x1E90FF},
        {"firebrick", 0xB22222},
        {"floralwhite", 0xFFFAF0},
        {"forestgreen", 0x228B22},
        {"fuchsia", 0xFF00FF},
        {"gainsboro", 0xDCDCDC},
        {"ghostwhite", 0xF8F8FF},
        {"gold", 0xFFD700},
        {"goldenrod", 0xDAA520},
        {"gray", 0x808080},
        {"green", 0x008000},
        {"greenyellow", 0xADFF2F},
        {"grey", 0x808080},
        {"honeydew", 0xF0FFF0},
        {"hotpink", 0xFF69B4},
        {"indianred", 0xCD5C5C},
        {"indigo", 0x4B0082},
        {"ivory", 0xFFFFF0},
        {"khaki", 0xF0E68C},
        {"lavender", 0xE6E6FA},
        {"lavenderblush", 0xFFF0F5},
        {"lawngreen", 0x7CFC00},
        {"lemonchiffon", 0xFFFACD},
        {"lightblue", 0xADD8E6},
        {"lightcoral", 0xF08080},
        {"lightcyan", 0xE0FFFF},
        {"lightgoldenrodyellow", 0xFAFAD2},
        {"lightgray", 0xD3D3D3},
        {"lightgreen", 0x90EE90},
        {"lightgrey", 0xD3D3D3},
        {"lightpink", 0xFFB6C1},
        {"lightsalmon", 0xFFA07A},
        {"lightseagreen", 0x20B2AA},
        {"lightskyblue", 0x87CEFA},
        {"lightslategray", 0x778899},
        {"lightslategrey", 0x778899},
        {"lightsteelblue", 0xB0C4DE},
        {"lightyellow", 0xFFFFE0},
        {"lime", 0x00FF00},
        {"limegreen", 0x32CD32},
        {"linen", 0xFAF0E6},
        {"magenta", 0xFF00FF},
        {"maroon", 0x800000},
        {"mediumaquamarine", 0x66CDAA},
        {"mediumblue", 0x0000CD},
        {"mediumorchid", 0xBA55D3},
        {"mediumpurple", 0x9370DB},
        {"mediumseagreen", 0x3CB371},
        {"mediumslateblue", 0x7B68EE},
        {"mediumspringgreen", 0x00FA9A},
        {"mediumturquoise", 0x48D1CC},
        {"mediumvioletred", 0xC71585},
        {"midnightblue", 0x191970},
        {"mintcream", 0xF5FFFA},
        {"mistyrose", 0xFFE4E1},
        {"moccasin", 0xFFE4B5},
        {"navajowhite", 0xFFDEAD},
        {"navy", 0x000080},
        {"oldlace", 0xFDF5E6},
        {"olive", 0x808000},
        {"olivedrab", 0x6B8E23},
        {"orange", 0xFFA500},
        {"orangered", 0xFF4500},
        {"orchid", 0xDA70D6},
        {"palegoldenrod", 0xEEE8AA},
        {"palegreen", 0x98FB98},
        {"paleturquoise", 0xAFEEEE},
        {"palevioletred", 0xDB7093},
        {"papayawhip", 0xFFEFD5},
        {"peachpuff", 0xFFDAB9},
        {"peru", 0xCD853F},
        {"pink", 0xFFC0CB},
        {"plum", 0xDDA0DD},
        {"powderblue", 0xB0E0E6},
        {"purple", 0x800080},
        {"rebeccapurple", 0x663399},
        {"red", 0xFF0000},
        {"rosybrown", 0xBC8F8F},
        {"royalblue", 0x4169E1},
        {"saddlebrown", 0x8B4513},
        {"salmon", 0xFA8072},
        {"sandybrown", 0xF4A460},
        {"seagreen", 0x2E8B57},
        {"seashell", 0xFFF5EE},
        {"sienna", 0xA0522D},
        {"silver", 0xC0C0C0},
        {"skyblue", 0x87CEEB},
        {"slateblue", 0x6A5ACD},
        {"slategray", 0x708090},
        {"slategrey", 0x708090},
        {"snow", 0xFFFAFA},
        {"springgreen", 0x00FF7F},
        {"steelblue", 0x4682B4},
        {"tan", 0xD2B48C},
        {"teal", 0x008080},
        {"thistle", 0xD8BFD8},
        {"tomato", 0xFF6347},
        {"turquoise", 0x40E0D0},
        {"violet", 0xEE82EE},
        {"wheat", 0xF5DEB3},
        {"white", 0xFFFFFF},
        {"whitesmoke", 0xF5F5F5},
        {"yellow", 0xFFFF00},
        {"yellowgreen", 0x9ACD32}
    };

    static const std::map<std::string, ElementId> elementmap = {
        {"circle", ElementId::Circle},
        //{"clipPath", ElementId::ClipPath},
        //{"defs", ElementId::Defs},
        //{"ellipse", ElementId::Ellipse},
        {"g", ElementId::G},
        //{"line", ElementId::Line},
        //{"linearGradient", ElementId::LinearGradient},
        //{"marker", ElementId::Marker},
        //{"mask", ElementId::Mask},
        {"path", ElementId::Path},
        //{"pattern", ElementId::Pattern},
        //{"polygon", ElementId::Polygon},
        //{"polyline", ElementId::Polyline},
        //{"radialGradient", ElementId::RadialGradient},
        {"rect", ElementId::Rect},
        //{"stop", ElementId::Stop},
        //{"style", ElementId::Style},
        {"solidColor", ElementId::SolidColor},
        {"svg", ElementId::Svg},
        //{"symbol", ElementId::Symbol},
        //{"use", ElementId::Use}
    };

    static const std::map<std::string, PropertyId> propertymap = {
        {"class", PropertyId::Class},
        {"clipPathUnits", PropertyId::ClipPathUnits},
        {"cx", PropertyId::Cx},
        {"cy", PropertyId::Cy},
        {"d", PropertyId::D},
        {"fx", PropertyId::Fx},
        {"fy", PropertyId::Fy},
        {"gradientTransform", PropertyId::GradientTransform},
        {"gradientUnits", PropertyId::GradientUnits},
        {"height", PropertyId::Height},
        {"id", PropertyId::Id},
        {"markerHeight", PropertyId::MarkerHeight},
        {"markerUnits", PropertyId::MarkerUnits},
        {"markerWidth", PropertyId::MarkerWidth},
        {"maskContentUnits", PropertyId::MaskContentUnits},
        {"maskUnits", PropertyId::MaskUnits},
        {"offset", PropertyId::Offset},
        {"orient", PropertyId::Orient},
        {"patternContentUnits", PropertyId::PatternContentUnits},
        {"patternTransform", PropertyId::PatternTransform},
        {"patternUnits", PropertyId::PatternUnits},
        {"points", PropertyId::Points},
        {"preserveAspectRatio", PropertyId::PreserveAspectRatio},
        {"r", PropertyId::R},
        {"refX", PropertyId::RefX},
        {"refY", PropertyId::RefY},
        {"rx", PropertyId::Rx},
        {"ry", PropertyId::Ry},
        {"spreadMethod", PropertyId::SpreadMethod},
        {"style", PropertyId::Style},
        {"transform", PropertyId::Transform},
        {"viewBox", PropertyId::ViewBox},
        {"width", PropertyId::Width},
        {"x", PropertyId::X},
        {"x1", PropertyId::X1},
        {"x2", PropertyId::X2},
        {"xlink:href", PropertyId::Href},
        {"y", PropertyId::Y},
        {"y1", PropertyId::Y1},
        {"y2", PropertyId::Y2}
    };

    static const std::map<std::string, PropertyId> csspropertymap = {
        {"clip-path", PropertyId::Clip_Path},
        {"clip-rule", PropertyId::Clip_Rule},
        {"color", PropertyId::Color},
        {"display", PropertyId::Display},
        {"fill", PropertyId::Fill},
        {"fill-opacity", PropertyId::Fill_Opacity},
        {"fill-rule", PropertyId::Fill_Rule},
        {"marker-end", PropertyId::Marker_End},
        {"marker-mid", PropertyId::Marker_Mid},
        {"marker-start", PropertyId::Marker_Start},
        {"mask", PropertyId::Mask},
        {"opacity", PropertyId::Opacity},
        {"overflow", PropertyId::Overflow},
        {"solid-color", PropertyId::Solid_Color},
        {"solid-opacity", PropertyId::Solid_Opacity},
        {"stop-color", PropertyId::Stop_Color},
        {"stop-opacity", PropertyId::Stop_Opacity},
        {"stroke", PropertyId::Stroke},
        {"stroke-dasharray", PropertyId::Stroke_Dasharray},
        {"stroke-dashoffset", PropertyId::Stroke_Dashoffset},
        {"stroke-linecap", PropertyId::Stroke_Linecap},
        {"stroke-linejoin", PropertyId::Stroke_Linejoin},
        {"stroke-miterlimit", PropertyId::Stroke_Miterlimit},
        {"stroke-opacity", PropertyId::Stroke_Opacity},
        {"stroke-width", PropertyId::Stroke_Width},
        {"visibility", PropertyId::Visibility}
    };

    static inline ElementId elementId(const std::string& name)
    {
        auto it = elementmap.find(name);
        if (it == elementmap.end())
        {
            printf("ElementId::Unknown");
            return ElementId::Unknown;
        }

        return it->second;
    }

    static inline PropertyId cssPropertyId(const std::string& name)
    {
        auto it = csspropertymap.find(name);
        if (it == csspropertymap.end())
            return PropertyId::Unknown;

        return it->second;
    }

    static inline PropertyId propertyId(const std::string& name)
    {
        auto it = propertymap.find(name);
        if (it == propertymap.end())
            return cssPropertyId(name);

        return it->second;
    }

#define IS_STARTNAMECHAR(c) (IS_ALPHA(c) ||  (c) == '_' || (c) == ':')
#define IS_NAMECHAR(c) (IS_STARTNAMECHAR(c) || IS_NUM(c) || (c) == '-' || (c) == '.')
    static inline bool readIdentifier(const char*& ptr, const char* end, std::string& value)
    {
        if (ptr >= end || !IS_STARTNAMECHAR(*ptr))
            return false;

        auto start = ptr;
        ++ptr;
        while (ptr < end && IS_NAMECHAR(*ptr))
            ++ptr;

        value.assign(start, ptr);
        return true;
    }

    #define IS_CSS_STARTNAMECHAR(c) (IS_ALPHA(c) || (c) == '_')
    #define IS_CSS_NAMECHAR(c) (IS_CSS_STARTNAMECHAR(c) || IS_NUM(c) || (c) == '-')
    static inline bool readCSSIdentifier(const char*& ptr, const char* end, std::string& value)///
    {
        if(ptr >= end || !IS_CSS_STARTNAMECHAR(*ptr))
            return false;

        auto start = ptr;
        ++ptr;
        while(ptr < end && IS_CSS_NAMECHAR(*ptr))
            ++ptr;

        value.assign(start, ptr);
        return true;
    }

    #define IS_SELECTOR_STARTNAMECHAR(c) (IS_CSS_STARTNAMECHAR(c) || (c) == '*' || (c) == '#' || (c) == '.' || (c) == '[' || (c) == ':')


    static inline bool decodeText(const char* ptr, const char* end, std::string& value)
    {
        value.clear();
        while (ptr < end)
        {
            auto ch = *ptr;
            ++ptr;
            if (ch != '&')
            {
                value.push_back(ch);
                continue;
            }

                    if(Utils::skipDesc(ptr, end, '#'))///
                    {
                        int base = 10;
                        if(Utils::skipDesc(ptr, end, 'x'))
                            base = 16;

                        unsigned int cp;
                        if(!Utils::parseInteger(ptr, end, cp, base))
                            return false;

                        char c[5] = {0, 0, 0, 0, 0};
                        if(cp < 0x80)
                        {
                            c[1] = 0;
                            c[0] = cp;
                        }
                        else if(cp < 0x800)
                        {
                            c[2] = 0;
                            c[1] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[0] = cp | 0xC0;
                        }
                        else if(cp < 0x10000)
                        {
                            c[3] = 0;
                            c[2] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[1] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[0] = cp | 0xE0;
                        }
                        else if(cp < 0x200000)
                        {
                            c[4] = 0;
                            c[3] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[2] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[1] = (cp & 0x3F) | 0x80;
                            cp >>= 6;
                            c[0] = cp | 0xF0;
                        }

                        value.append(c);
                    }
                    else
                    {
                        if(Utils::skipDesc(ptr, end, "amp"))
                            value.push_back('&');
                        else if(Utils::skipDesc(ptr, end, "lt"))
                            value.push_back('<');
                        else if(Utils::skipDesc(ptr, end, "gt"))
                            value.push_back('>');
                        else if(Utils::skipDesc(ptr, end, "quot"))
                            value.push_back('\"');
                        else if(Utils::skipDesc(ptr, end, "apos"))
                            value.push_back('\'');
                        else
                            return false;
                    }

                    if(!Utils::skipDesc(ptr, end, ';'))
                        return false;
        }

        return true;
    }

    static inline void parseStyle(const std::string& string, Element* element)///
    {
        auto ptr = string.data();
        auto end = ptr + string.size();

        std::string name;
        std::string value;
        Utils::skipWs(ptr, end);
        while(ptr < end && readCSSIdentifier(ptr, end, name))
        {
            Utils::skipWs(ptr, end);
            if(!Utils::skipDesc(ptr, end, ':'))
                return;
            Utils::skipWs(ptr, end);
            auto start = ptr;
            while(ptr < end && *ptr != ';')
                ++ptr;
            value.assign(start, Utils::rtrim(start, ptr));
            auto id = cssPropertyId(name);
            if(id != PropertyId::Unknown)
                element->set(id, value, 0x100);
            Utils::skipWsDelimiter(ptr, end, ';');
        }
    }

    enum LengthNegativeValuesMode
    {
        AllowNegativeLengths,
        ForbidNegativeLengths
    };

    enum class TransformType
    {
        Matrix,
        Rotate,
        Scale,
        SkewX,
        SkewY,
        Translate
    };

    class Parser
    {
    public:
        static Length parseLength(const std::string& string, LengthNegativeValuesMode mode, const Length& defaultValue)
        {
            if (string.empty())
                return defaultValue;

            auto ptr = string.data();
            auto end = ptr + string.size();

            double value;
            LengthUnits units;
            if (!parseLength(ptr, end, value, units, mode))
                return defaultValue;

            return Length{ value, units };
        }
            static LengthList parseLengthList(const std::string& string, LengthNegativeValuesMode mode)///
            {
                if(string.empty())
                    return LengthList{};

                auto ptr = string.data();
                auto end = ptr + string.size();

                double value;
                LengthUnits units;

                LengthList values;
                while(ptr < end)
                {
                    if(!parseLength(ptr, end, value, units, mode))
                        break;
                    values.emplace_back(value, units);
                    Utils::skipWsComma(ptr, end);
                }

                return values;
            }
            static double parseNumber(const std::string& string, double defaultValue)///
            {
                if(string.empty())
                    return defaultValue;

                auto ptr = string.data();
                auto end = ptr + string.size();

                double value;
                if(!Utils::parseNumber(ptr, end, value))
                    return defaultValue;

                return value;
            }
        static double parseNumberPercentage(const std::string& string, double defaultValue)
        {
            if (string.empty())
                return defaultValue;

            auto ptr = string.data();
            auto end = ptr + string.size();

            double value;
            if (!Utils::parseNumber(ptr, end, value))
                return defaultValue;

            if (Utils::skipDesc(ptr, end, '%'))
                value /= 100.0;
            return value < 0.0 ? 0.0 : value > 1.0 ? 1.0 : value;
        }
            static PointList parsePointList(const std::string& string)///
            {
                if(string.empty())
                    return PointList{};

                auto ptr = string.data();
                auto end = ptr + string.size();

                double x;
                double y;

                PointList values;
                while(ptr < end)
                {
                    if(!Utils::parseNumber(ptr, end, x)
                            || !Utils::skipWsComma(ptr, end)
                            || !Utils::parseNumber(ptr, end, y))
                        break;
                    values.emplace_back(x, y);
                    Utils::skipWsComma(ptr, end);
                }

                return values;
            }
        static Transform parseTransform(const std::string& string)
        {
            if (string.empty())
                return Transform{};

                    auto ptr = string.data();///
                    auto end = ptr + string.size();

                    TransformType type;
                    double values[6];
                    int count;

                    Transform transform;
                    while(ptr < end)
                    {
                        if(!parseTransform(ptr, end, type, values, count))
                            break;
                        Utils::skipWsComma(ptr, end);
                        switch(type) {
                        case TransformType::Matrix:
                            transform.transform(values[0], values[1], values[2], values[3], values[4], values[5]);
                            break;
                        case TransformType::Rotate:
                            if(count == 1)
                                transform.rotate(values[0], 0, 0);
                            else
                                transform.rotate(values[0], values[1], values[2]);
                            break;
                        case TransformType::Scale:
                            if(count == 1)
                                transform.scale(values[0], values[0]);
                            else
                                transform.scale(values[0], values[1]);
                            break;
                        case TransformType::SkewX:
                            transform.shear(values[0], 0);
                            break;
                        case TransformType::SkewY:
                            transform.shear(0, values[0]);
                            break;
                        case TransformType::Translate:
                            if(count == 1)
                                transform.translate(values[0], 0);
                            else
                                transform.translate(values[0], values[1]);
                            break;
                        }
                    }

                    return transform;
        }
        static Path parsePath(const std::string& string)
        {
            auto ptr = string.data();
            auto end = ptr + string.size();
            if (ptr >= end || !(*ptr == 'M' || *ptr == 'm'))
                return Path{};

            auto command = *ptr++;
            double c[6];
            bool f[2];

            Point startPoint;
            Point currentPoint;
            Point controlPoint;

            Path path;
            while (true)
            {
                Utils::skipWs(ptr, end);
                switch (command) {
                case 'M':
                case 'm':
                    if (!parseNumberList(ptr, end, c, 2))
                        break;

                    if (command == 'm')
                    {
                        c[0] += currentPoint.x;
                        c[1] += currentPoint.y;
                    }

                    path.moveTo(c[0], c[1]);
                    startPoint.x = currentPoint.x = controlPoint.x = c[0];
                    startPoint.y = currentPoint.y = controlPoint.y = c[1];
                    command = command == 'm' ? 'l' : 'L';
                    break;
                case 'L':
                case 'l':
                    if (!parseNumberList(ptr, end, c, 2))
                        break;

                    if (command == 'l')
                    {
                        c[0] += currentPoint.x;
                        c[1] += currentPoint.y;
                    }

                    path.lineTo(c[0], c[1]);
                    currentPoint.x = controlPoint.x = c[0];
                    currentPoint.y = controlPoint.y = c[1];
                    break;
                case 'Q':
                case 'q':
                    printf("case 'q'");
                    //                if(!parseNumberList(ptr, end, c, 4))
                    //                    break;

                    //                if(command == 'q')
                    //                {
                    //                    c[0] += currentPoint.x;
                    //                    c[1] += currentPoint.y;
                    //                    c[2] += currentPoint.x;
                    //                    c[3] += currentPoint.y;
                    //                }

                    //                path.quadTo(currentPoint.x, currentPoint.y, c[0], c[1], c[2], c[3]);
                    //                controlPoint.x = c[0];
                    //                controlPoint.y = c[1];
                    //                currentPoint.x = c[2];
                    //                currentPoint.y = c[3];
                    break;
                case 'C':
                case 'c':
                    if (!parseNumberList(ptr, end, c, 6))
                        break;

                    if (command == 'c')
                    {
                        c[0] += currentPoint.x;
                        c[1] += currentPoint.y;
                        c[2] += currentPoint.x;
                        c[3] += currentPoint.y;
                        c[4] += currentPoint.x;
                        c[5] += currentPoint.y;
                    }

                    path.cubicTo(c[0], c[1], c[2], c[3], c[4], c[5]);
                    controlPoint.x = c[2];
                    controlPoint.y = c[3];
                    currentPoint.x = c[4];
                    currentPoint.y = c[5];
                    break;
                case 'T':
                case 't':
                    printf("case 't'");
                    //                c[0] = 2 * currentPoint.x - controlPoint.x;
                    //                c[1] = 2 * currentPoint.y - controlPoint.y;
                    //                if(!parseNumberList(ptr, end, c + 2, 2))
                    //                    break;

                    //                if(command == 't')
                    //                {
                    //                    c[2] += currentPoint.x;
                    //                    c[3] += currentPoint.y;
                    //                }

                    //                path.quadTo(currentPoint.x, currentPoint.y, c[0], c[1], c[2], c[3]);
                    //                controlPoint.x = c[0];
                    //                controlPoint.y = c[1];
                    //                currentPoint.x = c[2];
                    //                currentPoint.y = c[3];
                    break;
                case 'S':
                case 's':
                    c[0] = 2 * currentPoint.x - controlPoint.x;
                    c[1] = 2 * currentPoint.y - controlPoint.y;
                    if (!parseNumberList(ptr, end, c + 2, 4))
                        break;

                    if (command == 's')
                    {
                        c[2] += currentPoint.x;
                        c[3] += currentPoint.y;
                        c[4] += currentPoint.x;
                        c[5] += currentPoint.y;
                    }

                    path.cubicTo(c[0], c[1], c[2], c[3], c[4], c[5]);
                    controlPoint.x = c[2];
                    controlPoint.y = c[3];
                    currentPoint.x = c[4];
                    currentPoint.y = c[5];
                    break;
                case 'H':
                case 'h':
                    if (!parseNumberList(ptr, end, c, 1))
                        break;

                    if (command == 'h')
                        c[0] += currentPoint.x;

                    path.lineTo(c[0], currentPoint.y);
                    currentPoint.x = controlPoint.x = c[0];
                    break;
                case 'V':
                case 'v':
                    if (!parseNumberList(ptr, end, c + 1, 1))
                        break;

                    if (command == 'v')
                        c[1] += currentPoint.y;

                    path.lineTo(currentPoint.x, c[1]);
                    currentPoint.y = controlPoint.y = c[1];
                    break;
                case 'A':
                case 'a':
                    printf("case 'a'");
                    //                if(!parseNumberList(ptr, end, c, 3)
                    //                        || !parseArcFlag(ptr, end, f[0])
                    //                        || !parseArcFlag(ptr, end, f[1])
                    //                        || !parseNumberList(ptr, end, c + 3, 2))
                    //                    break;

                    //                if(command == 'a')
                    //                {
                    //                    c[3] += currentPoint.x;
                    //                    c[4] += currentPoint.y;
                    //                }

                    //                path.arcTo(currentPoint.x, currentPoint.y, c[0], c[1], c[2], f[0], f[1], c[3], c[4]);
                    //                currentPoint.x = controlPoint.x = c[3];
                    //                currentPoint.y = controlPoint.y = c[4];
                    break;
                case 'Z':
                case 'z':
                    path.close();
                    currentPoint.x = controlPoint.x = startPoint.x;
                    currentPoint.y = controlPoint.y = startPoint.y;
                    break;
                default:
                    break;
                }

                Utils::skipWsComma(ptr, end);
                if (ptr >= end)
                    break;

                if (IS_ALPHA(*ptr))
                    command = *ptr++;
            }

            return path;
        }
        static std::string parseUrl(const std::string& string)
        {
            if (string.empty())
                return std::string{};

            //        auto ptr = string.data();/////////////////////////
            //        auto end = ptr + string.size();

            //        if(!Utils::skipDesc(ptr, end, "url(#"))
            //            return std::string{};

            //        std::string value;
            //        if(!Utils::readUntil(ptr, end, ')', value))
            //            return std::string{};

            //        return value;
        }
        //    static std::string parseHref(const std::string& string)///
        //    {
        //        if(string.size() > 1 && string.front() == '#')
        //            return string.substr(1);

        //        return std::string{};
        //    }
        static Rect parseViewBox(const std::string& string)
        {
            if (string.empty())
                return Rect::Invalid;

            auto ptr = string.data();
            auto end = ptr + string.size();

            double x;
            double y;
            double w;
            double h;
            if (!Utils::parseNumber(ptr, end, x)
                || !Utils::skipWsComma(ptr, end)
                || !Utils::parseNumber(ptr, end, y)
                || !Utils::skipWsComma(ptr, end)
                || !Utils::parseNumber(ptr, end, w)
                || !Utils::skipWsComma(ptr, end)
                || !Utils::parseNumber(ptr, end, h))
                return Rect::Invalid;

            if (w < 0.0 || h < 0.0)
                return Rect::Invalid;

            return Rect{ x, y, w, h };
        }
        static PreserveAspectRatio parsePreserveAspectRatio(const std::string& string)
        {
            if (string.empty())
                return PreserveAspectRatio{};

                    auto ptr = string.data();///////////////
                    auto end = ptr + string.size();

                    Align align{Align::xMidYMid};
                    MeetOrSlice scale{MeetOrSlice::Meet};
                    if(Utils::skipDesc(ptr, end, "none"))
                        align = Align::None;
                    else if(Utils::skipDesc(ptr, end, "xMinYMin"))
                        align = Align::xMinYMin;
                    else if(Utils::skipDesc(ptr, end, "xMidYMin"))
                        align = Align::xMidYMin;
                    else if(Utils::skipDesc(ptr, end, "xMaxYMin"))
                        align = Align::xMaxYMin;
                    else if(Utils::skipDesc(ptr, end, "xMinYMid"))
                        align = Align::xMinYMid;
                    else if(Utils::skipDesc(ptr, end, "xMidYMid"))
                        align = Align::xMidYMid;
                    else if(Utils::skipDesc(ptr, end, "xMaxYMid"))
                        align = Align::xMaxYMid;
                    else if(Utils::skipDesc(ptr, end, "xMinYMax"))
                        align = Align::xMinYMax;
                    else if(Utils::skipDesc(ptr, end, "xMidYMax"))
                        align = Align::xMidYMax;
                    else if(Utils::skipDesc(ptr, end, "xMaxYMax"))
                        align = Align::xMaxYMax;
                    else
                        return PreserveAspectRatio{};

                    Utils::skipWs(ptr, end);
                    if(Utils::skipDesc(ptr, end, "slice"))
                        scale = MeetOrSlice::Slice;
                    else
                        scale = MeetOrSlice::Meet;

                    return PreserveAspectRatio{align, scale};
        }
            static Angle parseAngle(const std::string& string)///
            {
                if(string.empty())
                    return Angle{};

                auto ptr = string.data();
                auto end = ptr + string.size();

                if(Utils::skipDesc(ptr, end, "auto"))
                    return MarkerOrient::Auto;

                double value;
                if(!Utils::parseNumber(ptr, end, value))
                    return Angle{};

                if(Utils::skipDesc(ptr, end, "rad"))
                    value *= 180.0 / pi;
                else if(Utils::skipDesc(ptr, end, "grad"))
                    value *= 360.0 / 400.0;

                return Angle{value, MarkerOrient::Angle};
            }
            static MarkerUnits parseMarkerUnits(const std::string& string)///
            {
                if(string.empty())
                    return MarkerUnits::StrokeWidth;

                if(string.compare("userSpaceOnUse") == 0)
                    return MarkerUnits::UserSpaceOnUse;
                return MarkerUnits::StrokeWidth;
            }
            static SpreadMethod parseSpreadMethod(const std::string& string)///
            {
                if(string.empty())
                    return SpreadMethod::Pad;

                if(string.compare("repeat") == 0)
                    return SpreadMethod::Repeat;
                if(string.compare("reflect") == 0)
                    return SpreadMethod::Reflect;
                return SpreadMethod::Pad;
            }
            static Units parseUnits(const std::string& string, Units defaultValue)///
            {
                if(string.empty())
                    return defaultValue;

                if(string.compare("userSpaceOnUse") == 0)
                    return Units::UserSpaceOnUse;
                if(string.compare("objectBoundingBox") == 0)
                    return Units::ObjectBoundingBox;
                return defaultValue;
            }
        static Color parseColor(const std::string& string, const StyledElement* element, const Color& defaultValue);
        static Paint parsePaint(const std::string& string, const StyledElement* element, const Color& defaultValue)
        {
            if (string.empty())
                return defaultValue;

            auto ptr = string.data();
            auto end = ptr + string.size();

            if (!Utils::skipDesc(ptr, end, "url(#"))
                return parseColor(string, element, defaultValue);
            printf("url!");
                    std::string ref;
                    if(!Utils::readUntil(ptr, end, ')', ref))
                        return defaultValue;

                    ++ptr;
                    Utils::skipWs(ptr, end);

                    std::string fallback{ptr, end};
                    if(fallback.empty())
                        return Paint{ref, Color::Transparent};
                    return Paint{ref, parseColor(fallback, element, defaultValue)};
        }
        static WindRule parseWindRule(const std::string& string)
        {
            if (string.empty())
                return WindRule::NonZero;

            //        if(string.compare("evenodd") == 0)///
            //            return WindRule::EvenOdd;
            //        return WindRule::NonZero;
        }
            static LineCap parseLineCap(const std::string& string)///
            {
                if(string.empty())
                    return LineCap::Butt;

                if(string.compare("round") == 0)
                    return LineCap::Round;
                if(string.compare("square") == 0)
                    return LineCap::Square;
                return LineCap::Butt;
            }
            static LineJoin parseLineJoin(const std::string& string)///
            {
                if(string.empty())
                    return LineJoin::Miter;

                if(string.compare("bevel") == 0)
                    return LineJoin::Bevel;
                if(string.compare("round") == 0)
                    return LineJoin::Round;
                return LineJoin::Miter;
            }
        static Display parseDisplay(const std::string& string)
        {
            if (string.empty())
                return Display::Inline;

            if (string.compare("none") == 0)
                return Display::None;
            return Display::Inline;
        }
        static Visibility parseVisibility(const std::string& string)
        {
            if (string.empty())
                return Visibility::Visible;

            if (string.compare("visible") == 0)
                return Visibility::Visible;
            return Visibility::Hidden;
        }
        static Overflow parseOverflow(const std::string& string, Overflow defaultValue)
        {
            if (string.empty())
                return defaultValue;

            //        if(string.compare("visible") == 0)///
            //            return Overflow::Visible;
            //        if(string.compare("hidden") == 0)
            //            return Overflow::Hidden;
            //        return defaultValue;
        }

    private:
        static bool parseLength(const char*& ptr, const char* end, double& value, LengthUnits& units, LengthNegativeValuesMode mode)
        {
            if (!Utils::parseNumber(ptr, end, value))
                return false;

            if (mode == ForbidNegativeLengths && value < 0.0)
                return false;

            char c[2] = { 0, 0 };
            if (ptr + 0 < end) c[0] = ptr[0];
            if (ptr + 1 < end) c[1] = ptr[1];

            switch (c[0]) {
            case '%':
                units = LengthUnits::Percent;
                ptr += 1;
                break;
            case 'p':
                if (c[1] == 'x')
                    units = LengthUnits::Px;
                else if (c[1] == 'c')
                    units = LengthUnits::Pc;
                else if (ptr[1] == 't')
                    units = LengthUnits::Pt;
                else
                    return false;
                ptr += 2;
                break;
            case 'i':
                if (c[1] == 'n')
                    units = LengthUnits::In;
                else
                    return false;
                ptr += 2;
                break;
            case 'c':
                if (c[1] == 'm')
                    units = LengthUnits::Cm;
                else
                    return false;
                ptr += 2;
                break;
            case 'm':
                if (c[1] == 'm')
                    units = LengthUnits::Mm;
                else
                    return false;
                ptr += 2;
                break;
            case 'e':
                if (c[1] == 'm')
                    units = LengthUnits::Em;
                else if (c[1] == 'x')
                    units = LengthUnits::Ex;
                else
                    return false;
                ptr += 2;
                break;
            default:
                units = LengthUnits::Number;
                break;
            }

            return true;
        }
        static bool parseNumberList(const char*& ptr, const char* end, double* values, int count)
        {
            for (int i = 0; i < count; i++)
            {
                if (!Utils::parseNumber(ptr, end, values[i]))
                    return false;
                Utils::skipWsComma(ptr, end);
            }

            return true;
        }
        static bool parseArcFlag(const char*& ptr, const char* end, bool& flag)
        {
            if (ptr < end && *ptr == '0')
                flag = false;
            else if (ptr < end && *ptr == '1')
                flag = true;
            else
                return false;

            ++ptr;
            Utils::skipWsComma(ptr, end);
            return true;
        }
            static bool parseColorComponent(const char*& ptr, const char* end, double& value)///
            {
                if(!Utils::parseNumber(ptr, end, value))
                    return false;

                if(Utils::skipDesc(ptr, end, '%'))
                    value *= 2.55;

                value = (value < 0.0) ? 0.0 : (value > 255.0) ? 255.0 : std::round(value);
                return true;
            }
            static bool parseTransform(const char*& ptr, const char* end, TransformType& type, double* values, int& count)///
            {
                int required = 0;
                int optional = 0;
                if(Utils::skipDesc(ptr, end, "matrix"))
                {
                    type = TransformType::Matrix;
                    required = 6;
                    optional = 0;
                }
                else if(Utils::skipDesc(ptr, end, "rotate"))
                {
                    type = TransformType::Rotate;
                    required = 1;
                    optional = 2;
                }
                else if(Utils::skipDesc(ptr, end, "scale"))
                {
                    type = TransformType::Scale;
                    required = 1;
                    optional = 1;
                }
                else if(Utils::skipDesc(ptr, end, "skewX"))
                {
                    type = TransformType::SkewX;
                    required = 1;
                    optional = 0;
                }
                else if(Utils::skipDesc(ptr, end, "skewY"))
                {
                    type = TransformType::SkewY;
                    required = 1;
                    optional = 0;
                }
                else if(Utils::skipDesc(ptr, end, "translate"))
                {
                    type = TransformType::Translate;
                    required = 1;
                    optional = 1;
                }
                else
                {
                    return false;
                }

                Utils::skipWs(ptr, end);
                if(ptr >= end || *ptr != '(')
                    return false;
                ++ptr;

                int maxCount = required + optional;
                count = 0;
                Utils::skipWs(ptr, end);
                while(count < maxCount)
                {
                    if(!Utils::parseNumber(ptr, end, values[count]))
                        break;
                    ++count;
                    Utils::skipWsComma(ptr, end);
                }

                if(ptr >= end || *ptr != ')' || !(count == required || count == maxCount))
                    return false;
                ++ptr;

                return true;
            }
    };


    //struct Selector;

    //struct AttributeSelector
    //{
    //    enum class MatchType
    //    {
    //        None,
    //        Equal,
    //        Includes,
    //        DashMatch,
    //        StartsWith,
    //        EndsWith,
    //        Contains
    //    };

    //    PropertyId id{PropertyId::Unknown};
    //    std::string value;
    //    MatchType matchType{MatchType::None};
    //};

    //using SelectorList = std::vector<Selector>;

    //struct PseudoClass
    //{
    //    enum class Type
    //    {
    //        Unknown,
    //        Empty,
    //        Root,
    //        Not,
    //        FirstChild,
    //        LastChild,
    //        OnlyChild,
    //        FirstOfType,
    //        LastOfType,
    //        OnlyOfType
    //    };

    //    Type type{Type::Unknown};
    //    SelectorList notSelectors;
    //};

    //struct SimpleSelector
    //{
    //    enum class Combinator
    //    {
    //        Descendant,
    //        Child,
    //        DirectAdjacent,
    //        InDirectAdjacent
    //    };

    //    ElementId id{ElementId::Star};
    //    std::vector<AttributeSelector> attributeSelectors;
    //    std::vector<PseudoClass> pseudoClasses;
    //    Combinator combinator{Combinator::Descendant};
    //};

    //struct Selector
    //{
    //    std::vector<SimpleSelector> simpleSelectors;
    //    int specificity{0};
    //};

    //struct Rule
    //{
    //    SelectorList selectors;
    //    PropertyList declarations;
    //};

    //class RuleMatchContext///
    //{
    //public:
    //    RuleMatchContext(const std::vector<Rule>& rules)
    //    {
    //        for(auto& rule : rules)
    //            for(auto& selector : rule.selectors)
    //                m_selectors.emplace(selector.specificity, std::make_pair(&selector, &rule.declarations));
    //    }

    //    std::vector<const PropertyList*> match(const Element* element) const
    //    {
    //        std::vector<const PropertyList*> declarations;
    //        auto it = m_selectors.begin();
    //        auto end = m_selectors.end();
    //        for(;it != end;++it)
    //        {
    //            auto& value = it->second;
    //            if(!selectorMatch(std::get<0>(value), element))
    //                continue;
    //            declarations.push_back(std::get<1>(value));
    //        }

    //        return declarations;
    //    }

    //private:
    //    bool selectorMatch(const Selector* selector, const Element* element) const
    //    {
    //        if(selector->simpleSelectors.empty())
    //            return false;

    //        if(selector->simpleSelectors.size() == 1)
    //            return simpleSelectorMatch(selector->simpleSelectors.front(), element);

    //        auto it = selector->simpleSelectors.rbegin();
    //        auto end = selector->simpleSelectors.rend();
    //        if(!simpleSelectorMatch(*it, element))
    //            return false;
    //        ++it;

    //        while(it != end)
    //        {
    //            switch(it->combinator) {
    //            case SimpleSelector::Combinator::Child:
    //            case SimpleSelector::Combinator::Descendant:
    //                element = element->parent;
    //                break;
    //            case SimpleSelector::Combinator::DirectAdjacent:
    //            case SimpleSelector::Combinator::InDirectAdjacent:
    //                element = element->previousSibling();
    //                break;
    //            }

    //            if(element == nullptr)
    //                return false;

    //            auto match = simpleSelectorMatch(*it, element);
    //            if(!match && (it->combinator != SimpleSelector::Combinator::Descendant && it->combinator != SimpleSelector::Combinator::InDirectAdjacent))
    //                return false;

    //            if(match || (it->combinator != SimpleSelector::Combinator::Descendant && it->combinator != SimpleSelector::Combinator::InDirectAdjacent))
    //                ++it;
    //        }

    //        return true;
    //    }
    //    bool simpleSelectorMatch(const SimpleSelector& selector, const Element* element) const
    //    {
    //        if(selector.id != ElementId::Star && selector.id != element->id)
    //            return false;

    //        for(auto& attributeSelector : selector.attributeSelectors)
    //            if(!attributeSelectorMatch(attributeSelector, element))
    //                return false;

    //        for(auto& pseudoClass : selector.pseudoClasses)
    //            if(!pseudoClassMatch(pseudoClass, element))
    //                return false;

    //        return true;
    //    }
    //    bool attributeSelectorMatch(const AttributeSelector& selector, const Element* element) const
    //    {
    //        auto& value = element->get(selector.id);
    //        if(value.empty())
    //            return false;

    //        if(selector.matchType == AttributeSelector::MatchType::None)
    //            return true;

    //        if(selector.matchType == AttributeSelector::MatchType::Equal)
    //            return selector.value == value;

    //        if(selector.matchType == AttributeSelector::MatchType::Includes)
    //        {
    //            auto ptr = value.data();
    //            auto end = ptr + value.size();
    //            while(ptr < end)
    //            {
    //                auto start = ptr;
    //                while(ptr < end && !IS_WS(*ptr))
    //                    ++ptr;

    //                if(selector.value == std::string(start, ptr))
    //                    return true;
    //                Utils::skipWs(ptr, end);
    //            }

    //            return false;
    //        }

    //        auto starts_with = [](const std::string& string, const std::string& prefix) {
    //            if(prefix.empty() || prefix.size() > string.size())
    //                return false;

    //            return string.compare(0, prefix.size(), prefix) == 0;
    //        };

    //        auto ends_with = [](const std::string& string, const std::string& suffix) {
    //            if(suffix.empty() || suffix.size() > string.size())
    //                return false;

    //            return string.compare(string.size() - suffix.size(), suffix.size(), suffix) == 0;
    //        };

    //        if(selector.matchType == AttributeSelector::MatchType::DashMatch)
    //        {
    //            if(selector.value == value)
    //                return true;

    //            return starts_with(value, selector.value + '-');
    //        }

    //        if(selector.matchType == AttributeSelector::MatchType::StartsWith)
    //            return starts_with(value, selector.value);

    //        if(selector.matchType == AttributeSelector::MatchType::EndsWith)
    //            return ends_with(value, selector.value);

    //        if(selector.matchType == AttributeSelector::MatchType::Contains)
    //            return value.find(selector.value) != std::string::npos;

    //        return false;
    //    }
    //    bool pseudoClassMatch(const PseudoClass& pseudo, const Element* element) const
    //    {
    //        if(pseudo.type == PseudoClass::Type::Empty)
    //            return element->children.empty();

    //        if(pseudo.type == PseudoClass::Type::Root)
    //            return element->parent == nullptr;

    //        if(pseudo.type == PseudoClass::Type::Not)
    //        {
    //            for(auto& selector : pseudo.notSelectors)
    //                if(selectorMatch(&selector, element))
    //                    return false;
    //            return true;
    //        }

    //        if(pseudo.type == PseudoClass::Type::FirstChild)
    //            return !element->previousSibling();

    //        if(pseudo.type == PseudoClass::Type::LastChild)
    //            return !element->nextSibling();

    //        if(pseudo.type == PseudoClass::Type::OnlyChild)
    //            return !(element->previousSibling() || element->nextSibling());

    //        if(pseudo.type == PseudoClass::Type::FirstOfType)
    //        {
    //            auto sibling = element->previousSibling();
    //            while(sibling)
    //            {
    //                if(sibling->id == element->id)
    //                    return false;
    //                sibling = element->previousSibling();
    //            }

    //            return true;
    //        }

    //        if(pseudo.type == PseudoClass::Type::LastOfType)
    //        {
    //            auto sibling = element->nextSibling();
    //            while(sibling)
    //            {
    //                if(sibling->id == element->id)
    //                    return false;
    //                sibling = element->nextSibling();
    //            }

    //            return true;
    //        }

    //        return false;
    //    }

    //private:
    //    std::multimap<int, std::pair<const Selector*, const PropertyList*>, std::less<int>> m_selectors;
    //};

    //class CSSParser///
    //{
    //public:
    //    CSSParser() = default;

    //    bool parseMore(const std::string& value)///
    //    {
    //        auto ptr = value.data();
    //        auto end = ptr + value.size();

    //        while(ptr < end)
    //        {
    //            Utils::skipWs(ptr, end);
    //            if(Utils::skipDesc(ptr, end, '@'))
    //            {
    //                if(!parseAtRule(ptr, end))
    //                    return false;
    //                continue;
    //            }

    //            Rule rule;
    //            if(!parseRule(ptr, end, rule))
    //                return false;
    //            m_rules.push_back(rule);
    //        }

    //        return true;
    //    }

    //    const std::vector<Rule>& rules() const { return m_rules; }

    //private:
    //    bool parseAtRule(const char*& ptr, const char* end) const///
    //    {
    //        int depth = 0;
    //        while(ptr < end)
    //        {
    //            auto ch = *ptr;
    //            ++ptr;
    //            if(ch == ';' && depth == 0)
    //                break;
    //            if(ch == '{') ++depth;
    //            else if(ch == '}' && depth > 0)
    //            {
    //                if(depth == 1)
    //                    break;
    //                --depth;
    //            }
    //        }

    //        return true;
    //    }
    //    bool parseRule(const char*& ptr, const char* end, Rule& rule) const
    //    {
    //        if(!parseSelectors(ptr, end, rule.selectors))
    //            return false;

    //        if(!parseDeclarations(ptr, end, rule.declarations))
    //            return false;

    //        return true;
    //    }
    //    bool parseSelectors(const char*& ptr, const char* end, SelectorList& selectors) const
    //    {
    //        Selector selector;
    //        if(!parseSelector(ptr, end, selector))
    //            return false;
    //        selectors.push_back(selector);

    //        while(Utils::skipDesc(ptr, end, ','))
    //        {
    //            Utils::skipWs(ptr, end);
    //            Selector selector;
    //            if(!parseSelector(ptr, end, selector))
    //                return false;
    //            selectors.push_back(selector);
    //        }

    //        return true;
    //    }
    //    bool parseDeclarations(const char*& ptr, const char* end, PropertyList& declarations) const
    //    {
    //        if(!Utils::skipDesc(ptr, end, '{'))
    //            return false;

    //        std::string name;
    //        std::string value;
    //        Utils::skipWs(ptr, end);
    //        do {
    ////            if(!readCSSIdentifier(ptr, end, name))
    ////                return false;
    //            Utils::skipWs(ptr, end);
    //            if(!Utils::skipDesc(ptr, end, ':'))
    //                return false;
    //            Utils::skipWs(ptr, end);
    //            auto start = ptr;
    //            while(ptr < end && !(*ptr == '!' || *ptr == ';' || *ptr == '}'))
    //                ++ptr;
    //            value.assign(start, Utils::rtrim(start, ptr));
    //            int specificity = 0x10;
    //            if(Utils::skipDesc(ptr, end, '!'))
    //            {
    //                if(!Utils::skipDesc(ptr, end, "important"))
    //                    return false;
    //                specificity = 0x1000;
    //            }

    //            auto id = cssPropertyId(name);
    //            if(id != PropertyId::Unknown)
    //                declarations.set(id, value, specificity);
    //            Utils::skipWsDelimiter(ptr, end, ';');
    //        } while(ptr < end && *ptr != '}');

    //        return Utils::skipDesc(ptr, end, '}');
    //    }
    //    bool parseSelector(const char*& ptr, const char* end, Selector& selector) const
    //    {
    //        do {
    //            SimpleSelector simpleSelector;
    //            if(!parseSimpleSelector(ptr, end, simpleSelector))
    //                return false;

    //            selector.specificity += (simpleSelector.id == ElementId::Star) ? 0x0 : 0x1;
    //            for(auto& attributeSelector : simpleSelector.attributeSelectors)
    //                selector.specificity += (attributeSelector.id == PropertyId::Id) ? 0x10000 : 0x100;

    //            selector.simpleSelectors.push_back(simpleSelector);
    //            Utils::skipWs(ptr, end);
    //        } while(ptr < end && IS_SELECTOR_STARTNAMECHAR(*ptr));

    //        return true;
    //    }
    //    bool parseSimpleSelector(const char*& ptr, const char* end, SimpleSelector& simpleSelector) const
    //    {
    //        std::string name;
    //        if(Utils::skipDesc(ptr, end, '*'))
    //            simpleSelector.id = ElementId::Star;
    ////        else if(readCSSIdentifier(ptr, end, name))
    ////            simpleSelector.id = elementId(name);

    //        while(ptr < end)
    //        {
    //            if(Utils::skipDesc(ptr, end, '#'))
    //            {
    //                AttributeSelector a;
    //                a.id = PropertyId::Id;
    ////                a.matchType = AttributeSelector::MatchType::Equal;
    ////                if(!readCSSIdentifier(ptr, end, a.value))
    ////                    return false;
    ////                simpleSelector.attributeSelectors.push_back(a);
    ////                continue;
    //            }

    //            if(Utils::skipDesc(ptr, end, '.'))
    //            {
    //                AttributeSelector a;
    //                a.id = PropertyId::Class;
    ////                a.matchType = AttributeSelector::MatchType::Includes;
    ////                if(!readCSSIdentifier(ptr, end, a.value))
    ////                    return false;
    ////                simpleSelector.attributeSelectors.push_back(a);
    ////                continue;
    //            }

    //            if(Utils::skipDesc(ptr, end, '['))
    //            {
    //                Utils::skipWs(ptr, end);
    ////                if(!readCSSIdentifier(ptr, end, name))
    ////                    return false;
    //                AttributeSelector a;
    //                a.id = propertyId(name);
    //                if(Utils::skipDesc(ptr, end, '='))
    //                    a.matchType = AttributeSelector::MatchType::Equal;
    //                else if(Utils::skipDesc(ptr, end, "~="))
    //                    a.matchType = AttributeSelector::MatchType::Includes;
    //                else if(Utils::skipDesc(ptr, end, "|="))
    //                    a.matchType = AttributeSelector::MatchType::DashMatch;
    //                else if(Utils::skipDesc(ptr, end, "^="))
    //                    a.matchType = AttributeSelector::MatchType::StartsWith;
    //                else if(Utils::skipDesc(ptr, end, "$="))
    //                    a.matchType = AttributeSelector::MatchType::EndsWith;
    //                else if(Utils::skipDesc(ptr, end, "*="))
    //                    a.matchType = AttributeSelector::MatchType::Contains;
    //                if(a.matchType != AttributeSelector::MatchType::None)
    //                {
    //                    Utils::skipWs(ptr, end);
    ////                    if(!readCSSIdentifier(ptr, end, a.value))
    ////                    {
    ////                        if(ptr >= end || !(*ptr == '\"' || *ptr == '\''))
    ////                            return false;

    ////                        auto quote = *ptr;
    ////                        ++ptr;
    ////                        if(!Utils::readUntil(ptr, end, quote, a.value))
    ////                            return false;
    ////                        ++ptr;
    ////                    }
    //                }

    //                Utils::skipWs(ptr, end);
    //                if(!Utils::skipDesc(ptr, end, ']'))
    //                    return false;
    //                simpleSelector.attributeSelectors.push_back(a);
    //                continue;
    //            }

    //            if(Utils::skipDesc(ptr, end, ':'))
    //            {
    ////                if(!readCSSIdentifier(ptr, end, name))
    ////                    return false;
    //                PseudoClass pseudo;
    //                if(name.compare("empty") == 0)
    //                    pseudo.type = PseudoClass::Type::Empty;
    //                else if(name.compare("root") == 0)
    //                    pseudo.type = PseudoClass::Type::Root;
    //                else if(name.compare("not") == 0)
    //                    pseudo.type = PseudoClass::Type::Not;
    //                else if(name.compare("first-child") == 0)
    //                    pseudo.type = PseudoClass::Type::FirstChild;
    //                else if(name.compare("last-child") == 0)
    //                    pseudo.type = PseudoClass::Type::LastChild;
    //                else if(name.compare("only-child") == 0)
    //                    pseudo.type = PseudoClass::Type::OnlyChild;
    //                else if(name.compare("first-of-type") == 0)
    //                    pseudo.type = PseudoClass::Type::FirstOfType;
    //                else if(name.compare("last-of-type") == 0)
    //                    pseudo.type = PseudoClass::Type::LastOfType;
    //                else if(name.compare("only-of-type") == 0)
    //                    pseudo.type = PseudoClass::Type::OnlyOfType;
    //                if(pseudo.type == PseudoClass::Type::Not)
    //                {
    //                    if(!Utils::skipDesc(ptr, end, '('))
    //                        return false;

    //                    Utils::skipWs(ptr, end);
    //                    if(!parseSelectors(ptr, end, pseudo.notSelectors))
    //                        return false;

    //                    Utils::skipWs(ptr, end);
    //                    if(!Utils::skipDesc(ptr, end, ')'))
    //                        return false;
    //                }

    //                simpleSelector.pseudoClasses.push_back(pseudo);
    //                continue;
    //            }

    //            break;
    //        }

    //        Utils::skipWs(ptr, end);
    //        if(Utils::skipDesc(ptr, end, '>'))
    //            simpleSelector.combinator = SimpleSelector::Combinator::Child;
    //        else if(Utils::skipDesc(ptr, end, '+'))
    //            simpleSelector.combinator = SimpleSelector::Combinator::DirectAdjacent;
    //        else if(Utils::skipDesc(ptr, end, '~'))
    //            simpleSelector.combinator = SimpleSelector::Combinator::InDirectAdjacent;

    //        return true;
    //    }

    //private:
    //    std::vector<Rule> m_rules;
    //};



    class LayoutObject
    {
    public:
        LayoutObject(LayoutId id)
            : id(id)
        {
        }
        virtual ~LayoutObject()
        {
        }
        virtual void render(RenderState&) const
        {
        }
        virtual void apply(RenderState&) const
        {
        }
        virtual Rect map(const Rect&) const
        {
            return Rect::Invalid;
        }

        virtual const Rect& fillBoundingBox() const { return Rect::Invalid; }
        virtual const Rect& strokeBoundingBox() const { return Rect::Invalid; }

        bool isPaint() const { return id == LayoutId::LinearGradient || id == LayoutId::RadialGradient || id == LayoutId::Pattern || id == LayoutId::SolidColor; }
        bool isHidden() const { return isPaint() || id == LayoutId::ClipPath || id == LayoutId::Mask || id == LayoutId::Marker; }

    public:
        LayoutId id;
    };

    using LayoutList = std::list<std::unique_ptr<LayoutObject>>;


    class LayoutContainer : public LayoutObject
    {
    public:
        LayoutContainer(LayoutId id)
            : LayoutObject(id)
        {
        }

        //    const Rect& fillBoundingBox() const///
        //    {
        //        if(m_fillBoundingBox.valid())
        //            return m_fillBoundingBox;

        //        for(const auto& child : children)
        //        {
        //            if(child->isHidden())
        //                continue;
        //            m_fillBoundingBox.unite(child->map(child->fillBoundingBox()));
        //        }

        //        return m_fillBoundingBox;
        //    }
        //    const Rect& strokeBoundingBox() const///
        //    {
        //        if(m_strokeBoundingBox.valid())
        //            return m_strokeBoundingBox;

        //        for(const auto& child : children)
        //        {
        //            if(child->isHidden())
        //                continue;
        //            m_strokeBoundingBox.unite(child->map(child->strokeBoundingBox()));
        //        }

        //        return m_strokeBoundingBox;
        //    }

        LayoutObject* addChild(std::unique_ptr<LayoutObject> child)
        {
            children.push_back(std::move(child));
            return &*children.back();
        }
        LayoutObject* addChildIfNotEmpty(std::unique_ptr<LayoutContainer> child)
        {
            if (child->children.empty())
                return nullptr;

            return addChild(std::move(child));
        }
        void renderChildren(RenderState& state) const
        {
            for (const auto& child : children)
                child->render(state);
        }

    public:
        LayoutList children;

    protected:
        mutable Rect m_fillBoundingBox{ Rect::Invalid };
        mutable Rect m_strokeBoundingBox{ Rect::Invalid };
    };



    //static plutovg_matrix_t to_plutovg_matrix(const Transform& transform);
    //static plutovg_fill_rule_t to_plutovg_fill_rule(WindRule winding);
    //static plutovg_operator_t to_plutovg_operator(BlendMode mode);
    static plutovg_line_cap_t to_plutovg_line_cap(LineCap cap);
    static plutovg_line_join_t to_plutovg_line_join(LineJoin join);
    static void to_plutovg_stops(plutovg_gradient_t* gradient, const GradientStops& stops);
    //static void to_plutovg_path(plutovg_t* pluto, const Path& path);


    static plutovg_matrix_t to_plutovg_matrix(const Transform& transform)
    {
        plutovg_matrix_t matrix;
        plutovg_matrix_init(&matrix, transform.m00, transform.m10, transform.m01, transform.m11, transform.m02, transform.m12);
        return matrix;
    }

    static plutovg_fill_rule_t to_plutovg_fill_rule(WindRule winding)
    {
        return winding == WindRule::EvenOdd ? plutovg_fill_rule_even_odd : plutovg_fill_rule_non_zero;
    }

    static plutovg_operator_t to_plutovg_operator(BlendMode mode)
    {
        return mode == BlendMode::Src ? plutovg_operator_src : mode == BlendMode::Src_Over ? plutovg_operator_src_over : mode == BlendMode::Dst_In ? plutovg_operator_dst_in : plutovg_operator_dst_out;
    }

    //plutovg_line_cap_t to_plutovg_line_cap(LineCap cap)///
    //{
    //    return cap == LineCap::Butt ? plutovg_line_cap_butt : cap == LineCap::Round ? plutovg_line_cap_round : plutovg_line_cap_square;
    //}

    //plutovg_line_join_t to_plutovg_line_join(LineJoin join)///
    //{
    //    return join == LineJoin::Miter ? plutovg_line_join_miter : join == LineJoin::Round ? plutovg_line_join_round : plutovg_line_join_bevel;
    //}

    static plutovg_spread_method_t to_plutovg_spread_methood(SpreadMethod spread)///
    {
        return spread == SpreadMethod::Pad ? plutovg_spread_method_pad : spread == SpreadMethod::Reflect ? plutovg_spread_method_reflect : plutovg_spread_method_repeat;
    }

    static void to_plutovg_stops(plutovg_gradient_t* gradient, const GradientStops& stops)///
    {
        for(const auto& stop : stops)
        {
            auto offset = std::get<0>(stop);
            auto& color = std::get<1>(stop);
          //  plutovg_gradient_add_stop_rgba(gradient, offset, color.r, color.g, color.b, color.a);
        }
    }

    static void to_plutovg_path(plutovg_t* pluto, const Path& path)
    {
        PathIterator it(path);
        std::array<Point, 3> p;
        while (!it.isDone())
        {
            switch (it.currentSegment(p)) {
            case PathCommand::MoveTo:
                plutovg_move_to(pluto, p[0].x, p[0].y);
                break;
            case PathCommand::LineTo:
                plutovg_line_to(pluto, p[0].x, p[0].y);
                break;
            case PathCommand::CubicTo:
                plutovg_cubic_to(pluto, p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
                break;
            case PathCommand::Close:
                plutovg_close_path(pluto);
                break;
            }

            it.next();
        }
    }



    class Canvas
    {
    public:
        static std::shared_ptr<Canvas> create(unsigned char* data, unsigned int width, unsigned int height, unsigned int stride)
        {
            return std::shared_ptr<Canvas>(new Canvas(data, static_cast<int>(width), static_cast<int>(height), static_cast<int>(stride)));
        }
            static std::shared_ptr<Canvas> create(double x, double y, double width, double height)
            {
                if(width <= 0.0 || height <= 0.0)
                    return std::shared_ptr<Canvas>(new Canvas(0, 0, 1, 1));

                auto l = static_cast<int>(floor(x));
                auto t = static_cast<int>(floor(y));
                auto r = static_cast<int>(ceil(x + width));
                auto b = static_cast<int>(ceil(y + height));
                return std::shared_ptr<Canvas>(new Canvas(l, t, r - l, b - t));
            }
            static std::shared_ptr<Canvas> create(const Rect& box)
            {
                return create(box.x, box.y, box.w, box.h);
            }

        void setColor(const Color& color)
        {
            plutovg_set_source_rgba(pluto, color.r, color.g, color.b, color.a);
        }
            void setLinearGradient(double x1, double y1, double x2, double y2, const GradientStops& stops, SpreadMethod spread, const Transform& transform)///
            {
                auto gradient = nullptr;//plutovg_gradient_create_linear(x1, y1, x2, y2);
                auto matrix = to_plutovg_matrix(transform);
                to_plutovg_stops(gradient, stops);
                plutovg_gradient_set_spread(gradient, to_plutovg_spread_methood(spread));
                plutovg_gradient_set_matrix(gradient, &matrix);
                plutovg_set_source_gradient(pluto, gradient);
                plutovg_gradient_destroy(gradient);
            }
            void setRadialGradient(double cx, double cy, double r, double fx, double fy, const GradientStops& stops, SpreadMethod spread, const Transform& transform)///
            {
               // auto gradient = plutovg_gradient_create_radial(cx, cy, r, fx, fy, 0);
         /*       auto matrix = to_plutovg_matrix(transform);
                to_plutovg_stops(gradient, stops);
                plutovg_gradient_set_spread(gradient, to_plutovg_spread_methood(spread));
                plutovg_gradient_set_matrix(gradient, &matrix);
                plutovg_set_source_gradient(pluto, gradient);
                plutovg_gradient_destroy(gradient);*/
            }
            void setTexture(const Canvas* source, TextureType type, const Transform& transform)///
            {
                //auto texture = plutovg_texture_create(source->surface);
                //auto matrix = to_plutovg_matrix(transform);
                //if(type == TextureType::Plain)
                //    plutovg_texture_set_type(texture, plutovg_texture_type_plain);
                //else
                //    plutovg_texture_set_type(texture, plutovg_texture_type_tiled);

                //plutovg_texture_set_matrix(texture, &matrix);
                //plutovg_set_source_texture(pluto, texture);
               // plutovg_texture_destroy(texture);
            }

        void fill(const Path& path, const Transform& transform, WindRule winding, BlendMode mode, double opacity)
        {
            auto matrix = to_plutovg_matrix(transform);
            plutovg_matrix_multiply(&matrix, &matrix, &translation);
            to_plutovg_path(pluto, path);
            plutovg_set_matrix(pluto, &matrix);
            plutovg_set_fill_rule(pluto, to_plutovg_fill_rule(winding));
            plutovg_set_opacity(pluto, opacity);
            plutovg_set_operator(pluto, to_plutovg_operator(mode));
            plutovg_fill(pluto);
        }
            void stroke(const Path& path, const Transform& transform, double width, LineCap cap, LineJoin join, double miterlimit, const DashData& dash, BlendMode mode, double opacity)///
            {
                auto matrix = to_plutovg_matrix(transform);///
                plutovg_matrix_multiply(&matrix, &matrix, &translation);
                to_plutovg_path(pluto, path);
                plutovg_set_matrix(pluto, &matrix);
                plutovg_set_line_width(pluto, width);
                plutovg_set_line_cap(pluto, to_plutovg_line_cap(cap));
                plutovg_set_line_join(pluto, to_plutovg_line_join(join));
                plutovg_set_miter_limit(pluto, miterlimit);
                plutovg_set_dash(pluto, dash.offset, dash.array.data(), static_cast<int>(dash.array.size()));
                plutovg_set_operator(pluto, to_plutovg_operator(mode));
                plutovg_set_opacity(pluto, opacity);
                plutovg_stroke(pluto);
            }
            void blend(const Canvas* source, BlendMode mode, double opacity)
            {
                plutovg_set_source_surface(pluto, source->surface, source->rect.x, source->rect.y);
                plutovg_set_operator(pluto, to_plutovg_operator(mode));
                plutovg_set_opacity(pluto, opacity);
                plutovg_set_matrix(pluto, &translation);
                plutovg_paint(pluto);
            }
            void mask(const Rect& clip, const Transform& transform)
            {
                auto matrix = to_plutovg_matrix(transform);
                auto path = plutovg_path_create();
                plutovg_path_add_rect(path, clip.x, clip.y, clip.w, clip.h);
                //plutovg_path_transform(path, &matrix);
                //plutovg_rect(pluto, rect.x, rect.y, rect.w, rect.h);
                //plutovg_add_path(pluto, path);
                plutovg_path_destroy(path);

                plutovg_set_source_rgba(pluto, 0, 0, 0, 0);
                plutovg_set_fill_rule(pluto, plutovg_fill_rule_even_odd);
                plutovg_set_operator(pluto, plutovg_operator_src);
                plutovg_set_opacity(pluto, 0.0);
                plutovg_set_matrix(pluto, &translation);
                plutovg_fill(pluto);
            }

        void clear(unsigned int value)
        {
            auto r = (value >> 24) & 0xFF;
            auto g = (value >> 16) & 0xFF;
            auto b = (value >> 8) & 0xFF;
            auto a = (value >> 0) & 0xFF;

            plutovg_set_source_rgba(pluto, r / 255.0, g / 255.0, b / 255.0, a / 255.0);
            plutovg_set_opacity(pluto, 1.0);
            plutovg_set_operator(pluto, plutovg_operator_src);
            plutovg_paint(pluto);
        }
        void rgba()
        {
            auto width = plutovg_surface_get_width(surface);
            auto height = plutovg_surface_get_height(surface);
            auto stride = plutovg_surface_get_stride(surface);
            auto data = plutovg_surface_get_data(surface);
            for (int y = 0; y < height; y++)
            {
                auto pixels = reinterpret_cast<uint32_t*>(data + stride * y);
                for (int x = 0; x < width; x++)
                {
                    auto pixel = pixels[x];
                    auto a = (pixel >> 24) & 0xFF;
                    if (a == 0)
                        continue;

                    auto r = (pixel >> 16) & 0xFF;
                    auto g = (pixel >> 8) & 0xFF;
                    auto b = (pixel >> 0) & 0xFF;
                    if (a != 255)
                    {
                        r = (r * 255) / a;
                        g = (g * 255) / a;
                        b = (b * 255) / a;
                    }

                    pixels[x] = (a << 24) | (b << 16) | (g << 8) | r;
                }
            }
        }
            void luminance()///
            {
                auto width = plutovg_surface_get_width(surface);
                auto height = plutovg_surface_get_height(surface);
                auto stride = plutovg_surface_get_stride(surface);
                auto data = plutovg_surface_get_data(surface);
                for(int y = 0;y < height;y++)
                {
                    auto pixels = reinterpret_cast<uint32_t*>(data + stride * y);
                    for(int x = 0;x < width;x++)
                    {
                        auto pixel = pixels[x];
                        auto r = (pixel >> 16) & 0xFF;
                        auto g = (pixel >> 8) & 0xFF;
                        auto b = (pixel >> 0) & 0xFF;
                        auto l = (2*r + 3*g + b) / 6;

                        pixels[x] = l << 24;
                    }
                }
            }

        //    unsigned int width() const
        //    {
        //        return plutovg_surface_get_width(surface);
        //    }
        //    unsigned int height() const
        //    {
        //        return plutovg_surface_get_height(surface);
        //    }
        //    unsigned int stride() const
        //    {
        //        return plutovg_surface_get_stride(surface);
        //    }
        //    unsigned char* data() const
        //    {
        //        return plutovg_surface_get_data(surface);
        //    }
        Rect box() const
        {
            return Rect(rect.x, rect.y, rect.w, rect.h);
        }

        ~Canvas()
        {
            plutovg_surface_destroy(surface);
            plutovg_destroy(pluto);
        }
    private:
        Canvas(unsigned char* data, int width, int height, int stride)
        {
            surface = plutovg_surface_create_for_data(data, width, height, stride);
            pluto = plutovg_create(surface);
            plutovg_matrix_init_identity(&translation);
            plutovg_rect_init(&rect, 0, 0, width, height);
        }
            Canvas(int x, int y, int width, int height)
            {
                //surface = plutovg_surface_create(width, height);
                pluto = plutovg_create(surface);
                //plutovg_matrix_init_translate(&translation, -x, -y);
                plutovg_rect_init(&rect, x, y, width, height);
            }

        plutovg_surface_t* surface;
        plutovg_t* pluto;
        plutovg_matrix_t translation;
        plutovg_rect_t rect;
    };
    class LayoutClipPath;
    struct BlendInfo
    {
        const LayoutClipPath* clipper;
        const LayoutMask* masker;
        double opacity;
        Rect clip;
    };

    class RenderState
    {
    public:
        RenderState(const LayoutObject* object, RenderMode mode)
            : m_object(object), m_mode(mode)
        {
        }

        void beginGroup(RenderState& state, const BlendInfo& info)
        {
            if (!info.clipper && !info.clip.valid() && (m_mode == RenderMode::Display && !(info.masker || info.opacity < 1.0)))
            {
                canvas = state.canvas;
                return;
            }

            //        auto box = transform.map(m_object->strokeBoundingBox());
            //        box.intersect(transform.map(info.clip));
            //        box.intersect(state.canvas->box());
            //        canvas = Canvas::create(box);
        }
        void endGroup(RenderState& state, const BlendInfo& info);

        const LayoutObject* object() const { return m_object;}
        RenderMode mode() const { return m_mode; }
        const Rect& objectBoundingBox() const { return m_object->fillBoundingBox(); }

    public:
        std::shared_ptr<Canvas> canvas;
        Transform transform;

    private:
        const LayoutObject* m_object;
        RenderMode m_mode;
    };




    class LayoutClipPath : public LayoutContainer///
    {
    public:
        LayoutClipPath()
            : LayoutContainer(LayoutId::ClipPath)
        {
        }

        void apply(RenderState& state) const///
        {
            RenderState newState(this, RenderMode::Clipping);
            newState.canvas = Canvas::create(state.canvas->box());
            newState.transform = transform * state.transform;
            if(units == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                newState.transform.translate(box.x, box.y);
                newState.transform.scale(box.w, box.h);
            }

            renderChildren(newState);
            if(clipper) clipper->apply(newState);
            state.canvas->blend(newState.canvas.get(), BlendMode::Dst_In, 1.0);
        }

    public:
        Units units;
        Transform transform;
        const LayoutClipPath* clipper;
    };


    class LayoutMask : public LayoutContainer///
    {
    public:
        LayoutMask()
            : LayoutContainer(LayoutId::Mask)
        {
        }

        void apply(RenderState& state) const
        {
            Rect rect{x, y, width, height};
            if(units == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                rect.x = rect.x * box.w + box.x;
                rect.y = rect.y * box.h + box.y;
                rect.w = rect.w * box.w;
                rect.h = rect.h * box.h;
            }

            RenderState newState(this, state.mode());
            newState.canvas = Canvas::create(state.canvas->box());
            newState.transform = state.transform;
            if(contentUnits == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                newState.transform.translate(box.x, box.y);
                newState.transform.scale(box.w, box.h);
            }

            renderChildren(newState);
            if(clipper) clipper->apply(newState);
            if(masker) masker->apply(newState);
            newState.canvas->mask(rect, state.transform);
            newState.canvas->luminance();
            state.canvas->blend(newState.canvas.get(), BlendMode::Dst_In, opacity);
        }

    public:
        double x;
        double y;
        double width;
        double height;
        Units units;
        Units contentUnits;
        double opacity;
        const LayoutMask* masker;
        const LayoutClipPath* clipper;
    };

    class LayoutSymbol : public LayoutContainer
    {
    public:
        LayoutSymbol()
            : LayoutContainer(LayoutId::Symbol)
        {
        }

        void render(RenderState& state) const
        {
            //BlendInfo info{clipper, masker, opacity, clip};
            //RenderState newState(this, state.mode());
            //newState.transform = transform * state.transform;
            //newState.beginGroup(state, info);
            renderChildren(state);
            //newState.endGroup(state, info);
        }
        //    Rect map(const Rect& rect) const
        //    {
        //        return transform.map(rect);
        //    }

    public:
        double width;
        double height;
        Transform transform;
        Rect clip;
        double opacity;
        const LayoutMask* masker;
        const LayoutClipPath* clipper;
    };


    class LayoutGroup : public LayoutContainer
    {
    public:
        LayoutGroup()
            : LayoutContainer(LayoutId::Group)
        {
        }

        void render(RenderState& state) const
        {
            BlendInfo info{ clipper, masker, opacity, Rect::Invalid };
            RenderState newState(this, state.mode());
            newState.transform = transform * state.transform;
            newState.beginGroup(state, info);
            renderChildren(newState);
            newState.endGroup(state, info);
        }
        //    Rect map(const Rect& rect) const
        //    {
        //        return transform.map(rect);
        //    }

    public:
        Transform transform;
        double opacity;
        const LayoutMask* masker;
        const LayoutClipPath* clipper;
    };

    class LayoutMarker : public LayoutContainer///////
    {
    public:
        LayoutMarker()
            : LayoutContainer(LayoutId::Marker)
        {
        }

        Transform markerTransform(const Point& origin, double angle, double strokeWidth) const
        {
            auto transform = Transform::translated(origin.x, origin.y);
            if(orient.type() == MarkerOrient::Auto)
                transform.rotate(angle);
            else
                transform.rotate(orient.value());

            if(units == MarkerUnits::StrokeWidth)
                transform.scale(strokeWidth, strokeWidth);

            transform.translate(-refX, -refY);
            return transform;
        }
        Rect markerBoundingBox(const Point& origin, double angle, double strokeWidth) const
        {
            auto box = transform.map(strokeBoundingBox());
            auto transform = markerTransform(origin, angle, strokeWidth);
            return transform.map(box);
        }
        void renderMarker(RenderState& state, const Point& origin, double angle, double strokeWidth) const
        {
            BlendInfo info{clipper, masker, opacity, clip};
            RenderState newState(this, state.mode());
            newState.transform = transform * markerTransform(origin, angle, strokeWidth) * state.transform;
            newState.beginGroup(state, info);
            renderChildren(newState);
            newState.endGroup(state, info);
        }

    public:
        double refX;
        double refY;
        Transform transform;
        Angle orient;
        MarkerUnits units;
        Rect clip;
        double opacity;
        const LayoutMask* masker;
        const LayoutClipPath* clipper;
    };

    class LayoutPattern : public LayoutContainer//////
    {
    public:
        LayoutPattern()
            : LayoutContainer(LayoutId::Pattern)
        {
        }

        void apply(RenderState& state) const
        {
            Rect rect{x, y, width, height};
            if(units == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                rect.x = rect.x * box.w + box.x;
                rect.y = rect.y * box.h + box.y;
                rect.w = rect.w * box.w;
                rect.h = rect.h * box.h;
            }

            auto ctm = state.transform * transform;
            auto scalex = std::sqrt(ctm.m00 * ctm.m00 + ctm.m01 * ctm.m01);
            auto scaley = std::sqrt(ctm.m10 * ctm.m10 + ctm.m11 * ctm.m11);

            auto width = rect.w * scalex;
            auto height = rect.h * scaley;

            RenderState newState(this, RenderMode::Display);
            newState.canvas = Canvas::create(0, 0, width, height);
            newState.transform = Transform::scaled(scalex, scaley);

            if(viewBox.valid())
            {
                auto viewTransform = preserveAspectRatio.getMatrix(rect.w, rect.h, viewBox);
                newState.transform.premultiply(viewTransform);
            }
            else if(contentUnits == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                newState.transform.scale(box.w, box.h);
            }

            auto transform = this->transform;
            transform.translate(rect.x, rect.y);
            transform.scale(1.0/scalex, 1.0/scaley);

            renderChildren(newState);
            state.canvas->setTexture(newState.canvas.get(), TextureType::Tiled, transform);
        }

    public:
        double x;
        double y;
        double width;
        double height;
        Transform transform;
        Units units;
        Units contentUnits;
        Rect viewBox;
        PreserveAspectRatio preserveAspectRatio;
    };

    class LayoutGradient : public LayoutObject///?
    {
    public:
        LayoutGradient(LayoutId id)
            : LayoutObject(id)
        {
        }

    public:
        Transform transform;
        SpreadMethod spreadMethod;
        Units units;
        GradientStops stops;
    };

    class LayoutLinearGradient : public LayoutGradient///?
    {
    public:
        LayoutLinearGradient()
            : LayoutGradient(LayoutId::LinearGradient)
        {
        }

        void apply(RenderState& state) const
        {
            auto transform = this->transform;
            if(units == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                transform *= Transform(box.w, 0, 0, box.h, box.x, box.y);
            }

            state.canvas->setLinearGradient(x1, y1, x2, y2, stops, spreadMethod, transform);
        }

    public:
        double x1;
        double y1;
        double x2;
        double y2;
    };

    class LayoutRadialGradient : public LayoutGradient///?
    {
    public:
        LayoutRadialGradient()
            : LayoutGradient(LayoutId::RadialGradient)
        {
        }

        void apply(RenderState& state) const
        {
            auto transform = this->transform;
            if(units == Units::ObjectBoundingBox)
            {
                const auto& box = state.objectBoundingBox();
                transform *= Transform(box.w, 0, 0, box.h, box.x, box.y);
            }

            state.canvas->setRadialGradient(cx, cy, r, fx, fy, stops, spreadMethod, transform);
        }

    public:
        double cx;
        double cy;
        double r;
        double fx;
        double fy;
    };

    class LayoutSolidColor : public LayoutObject///
    {
    public:
        LayoutSolidColor()
            : LayoutObject(LayoutId::SolidColor)
        {
        }

        void apply(RenderState& state) const
        {
            state.canvas->setColor(color);
        }

    public:
        Color color;
    };

    class FillData
    {
    public:
        FillData() = default;

        void fill(RenderState& state, const Path& path) const
        {
            if (opacity == 0.0 || (painter == nullptr && color.isNone()))
                return;

            if(painter == nullptr)
            state.canvas->setColor(color);
                    else
                        painter->apply(state);

            state.canvas->fill(path, state.transform, fillRule, BlendMode::Src_Over, opacity);
        }

    public:
        const LayoutObject* painter{nullptr};
        Color color{ Color::Transparent };
        double opacity{ 0 };
        WindRule fillRule{ WindRule::NonZero };
    };

    class StrokeData
    {
    public:
        StrokeData() = default;

        void stroke(RenderState& state, const Path& path) const
        {
            if(opacity == 0.0 || (painter == nullptr && color.isNone()))
                return;

            if(painter == nullptr)//////////////////
                state.canvas->setColor(color);
            else
                painter->apply(state);

            state.canvas->stroke(path, state.transform, width, cap, join, miterlimit, dash, BlendMode::Src_Over, opacity);
        }
        void inflate(Rect& box) const
        {
            if(opacity == 0.0 || (painter == nullptr && color.isNone()))
                return;

            double caplimit = width / 2.0;//////////////
            if(cap == LineCap::Square)
                caplimit *= sqrt2;

            double joinlimit = width / 2.0;
            if(join == LineJoin::Miter)
                joinlimit *= miterlimit;

            double delta = std::max(caplimit, joinlimit);
            box.x -= delta;
            box.y -= delta;
            box.w += delta * 2.0;
            box.h += delta * 2.0;
        }

    public:
        const LayoutObject* painter{nullptr};
        Color color{Color::Transparent};
        double opacity{0};
        double width{1};
        double miterlimit{4};
        LineCap cap{LineCap::Butt};
        LineJoin join{LineJoin::Miter};
        DashData dash;
    };

    class MarkerPosition///
    {
    public:
        MarkerPosition(const LayoutMarker* marker, const Point& origin, double angle)
            : marker(marker), origin(origin), angle(angle)
        {
        }

    public:
        const LayoutMarker* marker;
        Point origin;
        double angle;
    };

    using MarkerPositionList = std::vector<MarkerPosition>;

    class MarkerData
    {
    public:
        MarkerData() = default;

        void add(const LayoutMarker* marker, const Point& origin, double angle)
        {
            positions.emplace_back(marker, origin, angle);
        }
        void render(RenderState& state) const
        {
            for(const auto& position : positions);
                //position.marker->renderMarker(state, position.origin, position.angle, strokeWidth);
        }
        void inflate(Rect& box) const
        {
            //for(const auto& position : positions)
                //box.unite(position.marker->markerBoundingBox(position.origin, position.angle, strokeWidth));
        }

    public:
        MarkerPositionList positions;
        double strokeWidth{1};
    };

    class LayoutShape : public LayoutObject
    {
    public:
        LayoutShape()
            : LayoutObject(LayoutId::Shape)
        {
        }

        void render(RenderState& state) const
        {
            if (visibility == Visibility::Hidden)
                return;

            BlendInfo info{ clipper, masker, 1.0, Rect::Invalid };
            RenderState newState(this, state.mode());
            newState.transform = transform * state.transform;
            newState.beginGroup(state, info);

            if (newState.mode() == RenderMode::Display)
            {
                fillData.fill(newState, path);
                //strokeData.stroke(newState, path);
                //markerData.render(newState);
            }
            else
            {
                newState.canvas->setColor(Color::Black);
                newState.canvas->fill(path, newState.transform, clipRule, BlendMode::Src, 1.0);
            }

            newState.endGroup(state, info);
        }
        //    Rect map(const Rect& rect) const
        //    {
        //        return transform.map(rect);
        //    }
        //    const Rect& fillBoundingBox() const
        //    {
        //        if(m_fillBoundingBox.valid())
        //            return m_fillBoundingBox;

        //        m_fillBoundingBox = path.box();
        //        return m_fillBoundingBox;
        //    }
        //    const Rect& strokeBoundingBox() const
        //    {
        //        if(m_strokeBoundingBox.valid())
        //            return m_strokeBoundingBox;

        //        m_strokeBoundingBox = fillBoundingBox();
        //        //strokeData.inflate(m_strokeBoundingBox);
        //        markerData.inflate(m_strokeBoundingBox);
        //        return m_strokeBoundingBox;
        //    }

    public:
        Path path;
        Transform transform;
        FillData fillData;
        //StrokeData strokeData;
        //MarkerData markerData;
        Visibility visibility;
        WindRule clipRule;
        const LayoutMask* masker;
        const LayoutClipPath* clipper;

    private:
        mutable Rect m_fillBoundingBox{ Rect::Invalid };
        mutable Rect m_strokeBoundingBox{ Rect::Invalid };
    };





    class StyledElement : public Element
    {
    public:
        StyledElement(ElementId id)
            : Element(id)
        {
        }

        Paint fill() const
        {
            auto& value = find(PropertyId::Fill);
            return Parser::parsePaint(value, this, Color::Black);
        }
            Paint stroke() const
            {
                auto& value = find(PropertyId::Stroke);
                return Parser::parsePaint(value, this, Color::Transparent);
            }

        Color color() const///
        {
            auto& value = find(PropertyId::Color);
            return Parser::parseColor(value, this, Color::Black);
        }
            Color stop_color() const///
            {
                auto& value = find(PropertyId::Stop_Color);
                return Parser::parseColor(value, this, Color::Black);
            }
            Color solid_color() const///
            {
                auto& value = find(PropertyId::Solid_Color);
                return Parser::parseColor(value, this, Color::Black);
            }

        double opacity() const
        {
            auto& value = get(PropertyId::Opacity);
            return Parser::parseNumberPercentage(value, 1.0);
        }
        double fill_opacity() const
        {
            auto& value = find(PropertyId::Fill_Opacity);
            return Parser::parseNumberPercentage(value, 1.0);
        }
            double stroke_opacity() const
            {
                auto& value = find(PropertyId::Stroke_Opacity);
                return Parser::parseNumberPercentage(value, 1.0);
            }
            double stop_opacity() const
            {
                auto& value = find(PropertyId::Stop_Opacity);
                return Parser::parseNumberPercentage(value, 1.0);
            }
        //    double solid_opacity() const///
        //    {
        //        auto& value = find(PropertyId::Solid_Opacity);
        //        return Parser::parseNumberPercentage(value, 1.0);
        //    }
            double stroke_miterlimit() const///
            {
                auto& value = find(PropertyId::Stroke_Miterlimit);
                return Parser::parseNumber(value, 4.0);
            }

            Length stroke_width() const///
            {
                auto& value = find(PropertyId::Stroke_Width);
                return Parser::parseLength(value, ForbidNegativeLengths, Length::One);
            }
            Length stroke_dashoffset() const///
            {
                auto& value = find(PropertyId::Stroke_Dashoffset);
                return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
            }
            LengthList stroke_dasharray() const///
            {
                auto& value = find(PropertyId::Stroke_Dasharray);
                return Parser::parseLengthList(value, ForbidNegativeLengths);
            }

        WindRule fill_rule() const
        {
            auto& value = find(PropertyId::Fill_Rule);
            return Parser::parseWindRule(value);
        }
        WindRule clip_rule() const
        {
            auto& value = find(PropertyId::Clip_Rule);
            return Parser::parseWindRule(value);
        }

            LineCap stroke_linecap() const///
            {
                auto& value = find(PropertyId::Stroke_Linecap);
                return Parser::parseLineCap(value);
            }
            LineJoin stroke_linejoin() const///
            {
                auto& value = find(PropertyId::Stroke_Linejoin);
                return Parser::parseLineJoin(value);
            }

        Display display() const
        {
            auto& value = get(PropertyId::Display);
            return Parser::parseDisplay(value);
        }
        Visibility visibility() const
        {
            auto& value = find(PropertyId::Visibility);
            return Parser::parseVisibility(value);
        }
            Overflow overflow() const
            {
                auto& value = get(PropertyId::Overflow);
                return Parser::parseOverflow(value, parent == nullptr ? Overflow::Visible : Overflow::Hidden);
            }

            std::string clip_path() const
            {
                auto& value = get(PropertyId::Clip_Path);
                return Parser::parseUrl(value);
            }
            std::string mask() const
            {
                auto& value = get(PropertyId::Mask);
                return Parser::parseUrl(value);
            }
            std::string marker_start() const
            {
                auto& value = find(PropertyId::Marker_Start);
                return Parser::parseUrl(value);
            }
            std::string marker_mid() const
            {
                auto& value = find(PropertyId::Marker_Mid);
                return Parser::parseUrl(value);
            }
            std::string marker_end() const
            {
                auto& value = find(PropertyId::Marker_End);
                return Parser::parseUrl(value);
            }

        bool isDisplayNone() const
        {
            return display() == Display::None;
        }
            bool isOverflowHidden() const
            {
                return overflow() == Overflow::Hidden;
            }
    };

    //class StyleElement : public Element/////////
    //{
    //public:
    //    StyleElement()
    //        : Element(ElementId::Style)
    //    {
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<StyleElement>();
    //    }
    //};


    Color Parser::parseColor(const std::string& string, const StyledElement* element, const Color& defaultValue)
    {
        if (string.empty())
            return defaultValue;

        auto ptr = string.data();
        auto end = ptr + string.size();

        if (Utils::skipDesc(ptr, end, '#'))
        {
            auto start = ptr;
            unsigned int value;
            if (!Utils::parseInteger(ptr, end, value, 16))
                return defaultValue;

            auto n = ptr - start;
            if (n != 3 && n != 6)
                return defaultValue;

            if (n == 3)
            {
                value = ((value & 0xf00) << 8) | ((value & 0x0f0) << 4) | (value & 0x00f);
                value |= value << 4;
            }

            auto r = (value & 0xff0000) >> 16;
            auto g = (value & 0x00ff00) >> 8;
            auto b = (value & 0x0000ff) >> 0;

            return Color{ r / 255.0, g / 255.0, b / 255.0 };
        }

        if (Utils::skipDesc(ptr, end, "rgb("))
        {
            double r, g, b;
            if (!Utils::skipWs(ptr, end)
                                || !parseColorComponent(ptr, end, r)
                                || !Utils::skipWsComma(ptr, end)
                                || !parseColorComponent(ptr, end, g)
                                || !Utils::skipWsComma(ptr, end)
                                || !parseColorComponent(ptr, end, b)
                                || !Utils::skipWs(ptr, end)
                                || !Utils::skipDesc(ptr, end, ')')
                )
                return defaultValue;

            return Color{ r / 255.0, g / 255.0, b / 255.0 };
        }

        if (Utils::skipDesc(ptr, end, "none"))
            return Color::Transparent;

        if (Utils::skipDesc(ptr, end, "currentColor"))
            return element->color();

        auto it = colormap.find(string);
        if (it == colormap.end())
            return defaultValue;

        auto value = it->second;
        auto r = (value & 0xff0000) >> 16;
        auto g = (value & 0x00ff00) >> 8;
        auto b = (value & 0x0000ff) >> 0;

        return Color{ r / 255.0, g / 255.0, b / 255.0 };
    }


    class GraphicsElement : public StyledElement
    {
    public:
        GraphicsElement(ElementId id)
            : StyledElement(id)
        {
        }

        Transform transform() const
        {
            auto& value = get(PropertyId::Transform);
            return Parser::parseTransform(value);
        }
    };



    //class DefsElement : public GraphicsElement///
    //{
    //public:
    //    DefsElement()
    //        : GraphicsElement(ElementId::Defs)
    //    {
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<DefsElement>();
    //    }
    //};






    class GeometryElement : public GraphicsElement
    {
    public:
        GeometryElement(ElementId id)
            : GraphicsElement(id)
        {
        }

        bool isGeometry() const { return true; }
        virtual void layout(LayoutContext* context, LayoutContainer* current) const;
        virtual Path path() const = 0;
    };

    class PathElement : public GeometryElement
    {
    public:
        PathElement()
            : GeometryElement(ElementId::Path)
        {
        }

        Path d() const
        {
            auto& value = get(PropertyId::D);
            return Parser::parsePath(value);
        }
        Path path() const
        {
            return d();
        }

            std::unique_ptr<Node> clone() const
            {
                return cloneElement<PathElement>();
            }
    };

    //class PolyElement : public GeometryElement////?
    //{
    //public:
    //    PolyElement(ElementId id)
    //        : GeometryElement(id)
    //    {
    //    }

    //    PointList points() const
    //    {
    //        auto& value = get(PropertyId::Points);
    //        return Parser::parsePointList(value);
    //    }
    //};

    //class PolygonElement : public PolyElement////?
    //{
    //public:
    //    PolygonElement()
    //        : PolyElement(ElementId::Polygon)
    //    {
    //    }

    //    Path path() const
    //    {
    //        auto points = this->points();
    //        if(points.empty())
    //            return Path{};

    //        Path path;
    //        path.moveTo(points[0].x, points[0].y);
    //        for(std::size_t i = 1;i < points.size();i++)
    //            path.lineTo(points[i].x, points[i].y);

    //        path.close();
    //        return path;
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<PolygonElement>();
    //    }
    //};

    //class PolylineElement : public PolyElement////?
    //{
    //public:
    //    PolylineElement()
    //        : PolyElement(ElementId::Polyline)
    //    {
    //    }

    //    Path path() const
    //    {
    //        auto points = this->points();
    //        if(points.empty())
    //            return Path{};

    //        Path path;
    //        path.moveTo(points[0].x, points[0].y);
    //        for(std::size_t i = 1;i < points.size();i++)
    //            path.lineTo(points[i].x, points[i].y);

    //        return path;
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<PolylineElement>();
    //    }
    //};

    class CircleElement : public GeometryElement
    {
    public:
        CircleElement()
            : GeometryElement(ElementId::Circle)
        {
        }

        Length cx() const
        {
            auto& value = get(PropertyId::Cx);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length cy() const
        {
            auto& value = get(PropertyId::Cy);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length r() const
        {
            auto& value = get(PropertyId::R);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
        }

        Path path() const
        {
            auto r = this->r();
            if (r.isZero())
                return Path{};

            LengthContext lengthContext(this);
            auto _cx = lengthContext.valueForLength(cx(), LengthMode::Width);
            auto _cy = lengthContext.valueForLength(cy(), LengthMode::Height);
            auto _r = lengthContext.valueForLength(r, LengthMode::Both);

            Path path;
            path.ellipse(_cx, _cy, _r, _r);
            return path;
        }

            std::unique_ptr<Node> clone() const
            {
                return cloneElement<CircleElement>();
            }
    };

    class EllipseElement : public GeometryElement////?
    {
    public:
        EllipseElement()
            : GeometryElement(ElementId::Ellipse)
        {
        }

        Length cx() const
        {
            auto& value = get(PropertyId::Cx);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length cy() const
        {
            auto& value = get(PropertyId::Cy);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length rx() const
        {
            auto& value = get(PropertyId::Rx);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
        }
        Length ry() const
        {
            auto& value = get(PropertyId::Ry);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
        }

        Path path() const
        {
            auto rx = this->rx();
            auto ry = this->ry();
            if(rx.isZero() || ry.isZero())
                return Path{};

            LengthContext lengthContext(this);
            auto _cx = lengthContext.valueForLength(cx(), LengthMode::Width);
            auto _cy = lengthContext.valueForLength(cy(), LengthMode::Height);
            auto _rx = lengthContext.valueForLength(rx, LengthMode::Width);
            auto _ry = lengthContext.valueForLength(ry, LengthMode::Height);

            Path path;
            path.ellipse(_cx, _cy, _rx, _ry);
            return path;
        }

        std::unique_ptr<Node> clone() const
        {
            return cloneElement<EllipseElement>();
        }
    };

    class LineElement : public GeometryElement////?
    {
    public:
        LineElement()
            : GeometryElement(ElementId::Line)
        {
        }

        Length x1() const
        {
            auto& value = get(PropertyId::X1);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length y1() const
        {
            auto& value = get(PropertyId::Y1);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length x2() const
        {
            auto& value = get(PropertyId::X2);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length y2() const
        {
            auto& value = get(PropertyId::Y2);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }

        Path path() const
        {
            LengthContext lengthContext(this);
            auto _x1 = lengthContext.valueForLength(x1(), LengthMode::Width);
            auto _y1 = lengthContext.valueForLength(y1(), LengthMode::Height);
            auto _x2 = lengthContext.valueForLength(x2(), LengthMode::Width);
            auto _y2 = lengthContext.valueForLength(y2(), LengthMode::Height);

            Path path;
            path.moveTo(_x1, _y1);
            path.lineTo(_x2, _y2);
            return path;
        }

        std::unique_ptr<Node> clone() const
        {
            return cloneElement<LineElement>();
        }
    };

    class RectElement : public GeometryElement
    {
    public:
        RectElement()
            : GeometryElement(ElementId::Rect)
        {
        }

        Length x() const
        {
            auto& value = get(PropertyId::X);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length y() const
        {
            auto& value = get(PropertyId::Y);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length rx() const
        {
            auto& value = get(PropertyId::Rx);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Unknown);
        }
        Length ry() const
        {
            auto& value = get(PropertyId::Ry);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Unknown);
        }
        Length width() const
        {
            auto& value = get(PropertyId::Width);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
        }
        Length height() const
        {
            auto& value = get(PropertyId::Height);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
        }

        Path path() const
        {
            auto w = this->width();
            auto h = this->height();
            if (w.isZero() || h.isZero())
                return Path{};

            LengthContext lengthContext(this);
            auto _x = lengthContext.valueForLength(x(), LengthMode::Width);
            auto _y = lengthContext.valueForLength(y(), LengthMode::Height);
            auto _w = lengthContext.valueForLength(w, LengthMode::Width);
            auto _h = lengthContext.valueForLength(h, LengthMode::Height);

            auto rx = this->rx();
            auto ry = this->ry();

            auto _rx = lengthContext.valueForLength(rx, LengthMode::Width);
            auto _ry = lengthContext.valueForLength(ry, LengthMode::Height);

            if (!rx.isValid()) _rx = _ry;
            if (!ry.isValid()) _ry = _rx;

            Path path;
            path.rect(_x, _y, _w, _h, _rx, _ry);
            return path;
        }

            std::unique_ptr<Node> clone() const
            {
                return cloneElement<RectElement>();
            }
    };


    class MarkerElement : public StyledElement////?
    {
    public:
        MarkerElement()
            : StyledElement(ElementId::Marker)
        {
        }

        Length refX() const
        {
            auto& value = get(PropertyId::RefX);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length refY() const
        {
            auto& value = get(PropertyId::RefY);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length markerWidth() const
        {
            auto& value = get(PropertyId::MarkerWidth);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::ThreePercent);
        }
        Length markerHeight() const
        {
            auto& value = get(PropertyId::MarkerHeight);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::ThreePercent);
        }
        Angle orient() const
        {
            auto& value = get(PropertyId::Orient);
            return Parser::parseAngle(value);
        }
        MarkerUnits markerUnits() const
        {
            auto& value = get(PropertyId::MarkerUnits);
            return Parser::parseMarkerUnits(value);
        }

        Rect viewBox() const
        {
            auto& value = get(PropertyId::ViewBox);
            return Parser::parseViewBox(value);
        }
        PreserveAspectRatio preserveAspectRatio() const
        {
            auto& value = get(PropertyId::PreserveAspectRatio);
            return Parser::parsePreserveAspectRatio(value);
        }
        std::unique_ptr<LayoutMarker> getMarker(LayoutContext* context) const;

        std::unique_ptr<Node> clone() const
        {
            return cloneElement<MarkerElement>();
        }
    };

    class MaskElement : public StyledElement////?
    {
    public:
        MaskElement()
            : StyledElement(ElementId::Mask)
        {
        }

        Length x() const
        {
            auto& value = get(PropertyId::X);
            return Parser::parseLength(value, AllowNegativeLengths, Length::MinusTenPercent);
        }
        Length y() const
        {
            auto& value = get(PropertyId::Y);
            return Parser::parseLength(value, AllowNegativeLengths, Length::MinusTenPercent);
        }
        Length width() const
        {
            auto& value = get(PropertyId::Width);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::OneTwentyPercent);
        }
        Length height() const
        {
            auto& value = get(PropertyId::Height);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::OneTwentyPercent);
        }
        Units maskUnits() const
        {
            auto& value = get(PropertyId::MaskUnits);
            return Parser::parseUnits(value, Units::ObjectBoundingBox);
        }
        Units maskContentUnits() const
        {
            auto& value = get(PropertyId::MaskContentUnits);
            return Parser::parseUnits(value, Units::UserSpaceOnUse);
        }
        std::unique_ptr<LayoutMask> getMasker(LayoutContext* context) const;

        std::unique_ptr<Node> clone() const
        {
            return cloneElement<MaskElement>();
        }
    };


    class PaintElement : public StyledElement////?
    {
    public:
        PaintElement(ElementId id)
            : StyledElement(id)
        {
        }

        bool isPaint() const { return true; }
        virtual std::unique_ptr<LayoutObject> getPainter(LayoutContext* context) const = 0;
    };



    class StopElement : public StyledElement////?
    {
    public:
        StopElement()
            : StyledElement(ElementId::Stop)
        {
        }

        double offset() const
        {
            auto& value = get(PropertyId::Offset);
            return Parser::parseNumberPercentage(value, 1.0);
        }
        Color stopColorWithOpacity() const
        {
            auto color = stop_color();
            color.a = stop_opacity();
            return color;
        }

        std::unique_ptr<Node> clone() const
        {
            return cloneElement<StopElement>();
        }
    };
    class ClipPathElement;


    class LayoutContext
    {
    public:
        LayoutContext(const ParseDocument* document, LayoutSymbol* root)
            : m_document(document), m_root(root)
        {
        }

        Element* getElementById(const std::string& id) const;
            LayoutObject* getResourcesById(const std::string& id) const/////
            {
                auto it = m_resourcesCache.find(id);
                if(it == m_resourcesCache.end())
                    return nullptr;

                return it->second;
            }
            LayoutObject* addToResourcesCache(const std::string& id, std::unique_ptr<LayoutObject> resources)///////
            {
                if(resources == nullptr)
                    return nullptr;

                m_resourcesCache.emplace(id, resources.get());
                return m_root->addChild(std::move(resources));
            }
            LayoutMask* getMasker(const std::string& id)
            {
                if(id.empty())
                    return nullptr;

                auto ref = getResourcesById(id);/////////
                if(ref && ref->id == LayoutId::Mask)
                    return static_cast<LayoutMask*>(ref);

                auto element = getElementById(id);
                if(element == nullptr || element->id != ElementId::Mask)
                    return nullptr;

                auto masker = static_cast<MaskElement*>(element)->getMasker(this);
                return static_cast<LayoutMask*>(addToResourcesCache(id, std::move(masker)));
            }
            //LayoutClipPath* getClipper(const std::string& id);
            LayoutMarker* getMarker(const std::string& id)
            {
                if(id.empty())
                    return nullptr;

                auto ref = getResourcesById(id);/////////
                if(ref && ref->id == LayoutId::Marker)
                    return static_cast<LayoutMarker*>(ref);

                auto element = getElementById(id);
                if(element == nullptr || element->id != ElementId::Marker)
                    return nullptr;

                auto marker = static_cast<MarkerElement*>(element)->getMarker(this);
                return static_cast<LayoutMarker*>(addToResourcesCache(id, std::move(marker)));
            }
            LayoutObject* getPainter(const std::string& id)
            {
                if(id.empty())
                    return nullptr;

                auto ref = getResourcesById(id);/////////
                if(ref && ref->isPaint())
                    return ref;

                auto element = getElementById(id);
                if(element == nullptr || !element->isPaint())
                    return nullptr;

                auto painter = static_cast<PaintElement*>(element)->getPainter(this);
                return addToResourcesCache(id, std::move(painter));
            }

        FillData fillData(const StyledElement* element)
        {
            auto fill = element->fill();
            if (fill.isNone())
                return FillData{};

            FillData fillData;
            //fillData.painter = nullptr;//getPainter(fill.ref());
            fillData.color = fill.color();
            fillData.opacity = element->opacity() * element->fill_opacity();
            fillData.fillRule = element->fill_rule();
            return fillData;
        }
            DashData dashData(const StyledElement* element)
            {
                return DashData{};
                auto dasharray = element->stroke_dasharray();
                if(dasharray.empty())
                    return DashData{};

                LengthContext lengthContex(element);/////////
                DashArray dashes;
                for(auto& dash : dasharray)
                {
                    auto value = lengthContex.valueForLength(dash, LengthMode::Both);
                    dashes.push_back(value);
                }

                auto num_dash = dashes.size();
                if(num_dash % 2)
                    num_dash *= 2;

                DashData dashData;
                dashData.array.resize(num_dash);
                double sum = 0.0;
                for(std::size_t i = 0;i < num_dash;i++)
                {
                    dashData.array[i] = dashes[i % dashes.size()];
                    sum += dashData.array[i];
                }

                if(sum == 0.0)
                    return DashData{};

                auto offset = lengthContex.valueForLength(element->stroke_dashoffset(), LengthMode::Both);
                dashData.offset = std::fmod(offset, sum);
                if(dashData.offset < 0.0)
                    dashData.offset += sum;

                return dashData;
            }
            StrokeData strokeData(const StyledElement* element)
            {
                auto stroke = element->stroke();
                if(stroke.isNone())
                    return StrokeData{};
                printf("strokeData");
                LengthContext lengthContex(element);/////////////
                StrokeData strokeData;
                strokeData.painter = getPainter(stroke.ref());
                strokeData.color = stroke.color();
                strokeData.opacity = element->opacity() * element->stroke_opacity();
                strokeData.width = lengthContex.valueForLength(element->stroke_width(), LengthMode::Both);
                strokeData.miterlimit = element->stroke_miterlimit();
                strokeData.cap = element->stroke_linecap();
                strokeData.join = element->stroke_linejoin();
                strokeData.dash = dashData(element);
                return strokeData;
            }
            MarkerData markerData(const GeometryElement* element, const Path& path)
            {
                auto markerStart = getMarker(element->marker_start());
                auto markerMid = getMarker(element->marker_mid());
                auto markerEnd = getMarker(element->marker_end());

                if(markerStart == nullptr && markerMid == nullptr && markerEnd == nullptr)
                    return MarkerData{};
                printf("markerData");
                LengthContext lengthContex(element);///////////
                MarkerData markerData;
                markerData.strokeWidth = lengthContex.valueForLength(element->stroke_width(), LengthMode::Both);

                PathIterator it(path);
                Point origin;
                Point startPoint;
                Point inslopePoints[2];
                Point outslopePoints[2];

                int index = 0;
                std::array<Point, 3> points;
                while(!it.isDone())
                {
                    switch(it.currentSegment(points)) {
                    case PathCommand::MoveTo:
                        startPoint = points[0];
                        inslopePoints[0] = origin;
                        inslopePoints[1] = points[0];
                        origin = points[0];
                        break;
                    case PathCommand::LineTo:
                        inslopePoints[0] = origin;
                        inslopePoints[1] = points[0];
                        origin = points[0];
                        break;
                    case PathCommand::CubicTo:
                        inslopePoints[0] = points[1];
                        inslopePoints[1] = points[2];
                        origin = points[2];
                        break;
                    case PathCommand::Close:
                        inslopePoints[0] = origin;
                        inslopePoints[1] = points[0];
                        origin = startPoint;
                        startPoint = Point{};
                        break;
                    }

                    index += 1;
                    it.next();

                    if(!it.isDone() && (markerStart || markerMid))
                    {
                        it.currentSegment(points);
                        outslopePoints[0] = origin;
                        outslopePoints[1] = points[0];

                        if(index == 1 && markerStart)
                        {
                            Point slope{outslopePoints[1].x - outslopePoints[0].x, outslopePoints[1].y - outslopePoints[0].y};
                            auto angle = 180.0 * std::atan2(slope.y, slope.x) / pi;

                            markerData.add(markerStart, origin, angle);
                        }

                        if(index > 1 && markerMid)
                        {
                            Point inslope{inslopePoints[1].x - inslopePoints[0].x, inslopePoints[1].y - inslopePoints[0].y};
                            Point outslope{outslopePoints[1].x - outslopePoints[0].x, outslopePoints[1].y - outslopePoints[0].y};
                            auto inangle = 180.0 * std::atan2(inslope.y, inslope.x) / pi;
                            auto outangle = 180.0 * std::atan2(outslope.y, outslope.x) / pi;
                            auto angle = (inangle + outangle) * 0.5;

                            markerData.add(markerMid, origin, angle);
                        }
                    }

                    if(it.isDone() && markerEnd)
                    {
                        Point slope{inslopePoints[1].x - inslopePoints[0].x, inslopePoints[1].y - inslopePoints[0].y};
                        auto angle = 180.0 * std::atan2(slope.y, slope.x) / pi;

                        markerData.add(markerEnd, origin, angle);
                    }
                }

                return markerData;
            }

            void addReference(const Element* element)////
            {
                m_references.insert(element);
            }
            void removeReference(const Element* element)///
            {
                m_references.erase(element);
            }
            bool hasReference(const Element* element) const///
            {
                return m_references.count(element);
            }

    private:
        const ParseDocument* m_document;
        LayoutSymbol* m_root;
        std::map<std::string, LayoutObject*> m_resourcesCache;
        std::set<const Element*> m_references;
    };


    class LayoutBreaker/////
    {
    public:
        LayoutBreaker(LayoutContext* context, const Element* element)
            : m_context(context), m_element(element)
        {
            context->addReference(element);
        }
        ~LayoutBreaker()
        {
            m_context->removeReference(m_element);
        }

    private:
        LayoutContext* m_context;
        const Element* m_element;
    };

    std::unique_ptr<LayoutMarker> MarkerElement::getMarker(LayoutContext *context) const////
    {
        auto markerWidth = this->markerWidth();
        auto markerHeight = this->markerHeight();
        if(markerWidth.isZero() || markerHeight.isZero() || context->hasReference(this))
            return nullptr;

        LengthContext lengthContext(this);
        auto _refX = lengthContext.valueForLength(refX(), LengthMode::Width);
        auto _refY = lengthContext.valueForLength(refY(), LengthMode::Height);
        auto _markerWidth = lengthContext.valueForLength(markerWidth, LengthMode::Width);
        auto _markerHeight = lengthContext.valueForLength(markerHeight, LengthMode::Height);

        auto viewBox = this->viewBox();
        auto preserveAspectRatio = this->preserveAspectRatio();
        auto viewTransform = preserveAspectRatio.getMatrix(_markerWidth, _markerHeight, viewBox);
        viewTransform.map(_refX, _refY, &_refX, &_refY);

        LayoutBreaker layoutBreaker(context, this);
        auto marker = make_unique<LayoutMarker>();
        marker->refX = _refX;
        marker->refY = _refY;
        marker->transform = viewTransform;
        marker->orient = orient();
        marker->units = markerUnits();
        marker->clip = isOverflowHidden() ? preserveAspectRatio.getClip(_markerWidth, _markerHeight, viewBox) : Rect::Invalid;
        marker->opacity = opacity();
        marker->masker = context->getMasker(mask());
        marker->clipper = nullptr;// context->getClipper(clip_path());
        layoutChildren(context, marker.get());
        return marker;
    }

    void RenderState::endGroup(RenderState& state, const BlendInfo& info)
    {
        if (state.canvas == canvas)
            return;

        if (info.clipper)
            printf("info.clipper");
        // info.clipper->apply(*this);

        if (info.masker && m_mode == RenderMode::Display)
            printf("info.masker");
        //info.masker->apply(*this);

        if (info.clip.valid())
            printf("info.clip.valid()");
        //canvas->mask(info.clip, transform);

    //state.canvas->blend(canvas.get(), BlendMode::Src_Over, m_mode == RenderMode::Display ? info.opacity : 1.0);
    }

    void GeometryElement::layout(LayoutContext* context, LayoutContainer* current) const
    {
        if (isDisplayNone())
            return;

        auto path = this->path();
        if (path.empty())
            return;

        auto shape = make_unique<LayoutShape>();
        shape->path = std::move(path);
        shape->transform = transform();
        shape->fillData = context->fillData(this);
        //shape->strokeData = context->strokeData(this);
        //shape->markerData = context->markerData(this, shape->path);
        shape->visibility = visibility();
        shape->clipRule = clip_rule();
        shape->masker = nullptr;// context->getMasker(mask());
        shape->clipper = nullptr;//context->getClipper(clip_path());
        current->addChild(std::move(shape));
    }

    std::unique_ptr<LayoutMask> MaskElement::getMasker(LayoutContext *context) const///
    {
        auto w = this->width();
        auto h = this->height();
        if(w.isZero() || h.isZero() || context->hasReference(this))
            return nullptr;

        LayoutBreaker layoutBreaker(context, this);
        auto masker = make_unique<LayoutMask>();
        masker->units = maskUnits();
        masker->contentUnits = maskContentUnits();
        masker->opacity = opacity();
        masker->clipper = nullptr;// context->getClipper(clip_path());
        masker->masker = context->getMasker(mask());

        LengthContext lengthContext(this, maskUnits());
        masker->x = lengthContext.valueForLength(x(), LengthMode::Width);
        masker->y = lengthContext.valueForLength(y(), LengthMode::Height);
        masker->width = lengthContext.valueForLength(w, LengthMode::Width);
        masker->height = lengthContext.valueForLength(h, LengthMode::Height);
        layoutChildren(context, masker.get());
        return masker;
    }


    class GElement : public GraphicsElement
    {
    public:
        GElement()
            : GraphicsElement(ElementId::G)
        {
        }

        void layout(LayoutContext* context, LayoutContainer* current) const
        {
            if (isDisplayNone())
                return;

            auto group = make_unique<LayoutGroup>();
            group->transform = transform();
            group->opacity = opacity();
            group->masker = nullptr;//context->getMasker(mask());
            group->clipper = nullptr;//context->getClipper(clip_path());
            layoutChildren(context, group.get());
            current->addChildIfNotEmpty(std::move(group));
        }
            std::unique_ptr<Node> clone() const
            {
                return cloneElement<GElement>();
            }
    };

    class SVGElement : public GraphicsElement
    {
    public:
        SVGElement()
            : GraphicsElement(ElementId::Svg)
        {
        }

        Length x() const
        {
            auto& value = get(PropertyId::X);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length y() const
        {
            auto& value = get(PropertyId::Y);
            return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
        }
        Length width() const
        {
            auto& value = get(PropertyId::Width);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
        }
        Length height() const
        {
            auto& value = get(PropertyId::Height);
            return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
        }

        Rect viewBox() const
        {
            auto& value = get(PropertyId::ViewBox);
            return Parser::parseViewBox(value);
        }
        PreserveAspectRatio preserveAspectRatio() const
        {
            auto& value = get(PropertyId::PreserveAspectRatio);
            return Parser::parsePreserveAspectRatio(value);
        }
        std::unique_ptr<LayoutSymbol> layoutDocument(const ParseDocument* document) const
        {
            if (isDisplayNone())
                return nullptr;

            auto w = this->width();
            auto h = this->height();
            if (w.isZero() || h.isZero())
                return nullptr;

            LengthContext lengthContext(this);
            auto _x = lengthContext.valueForLength(x(), LengthMode::Width);
            auto _y = lengthContext.valueForLength(y(), LengthMode::Height);
            auto _w = lengthContext.valueForLength(w, LengthMode::Width);
            auto _h = lengthContext.valueForLength(h, LengthMode::Height);

            auto viewBox = this->viewBox();
            auto preserveAspectRatio = this->preserveAspectRatio();
            auto viewTranslation = Transform::translated(_x, _y);
            auto viewTransform = preserveAspectRatio.getMatrix(_w, _h, viewBox);

            auto root = make_unique<LayoutSymbol>();
            root->width = _w;
            root->height = _h;
            root->transform = (viewTransform * viewTranslation) * transform();
            root->clip = /*isOverflowHidden() ? preserveAspectRatio.getClip(_w, _h, viewBox) :*/ Rect::Invalid;
            root->opacity = opacity();

            LayoutContext context(document, root.get());
            root->masker = nullptr;//context.getMasker(mask());
            root->clipper = nullptr;//context.getClipper(clip_path());
            layoutChildren(&context, root.get());
            return root;
        }

        void layout(LayoutContext* context, LayoutContainer* current) const
        {
            if (isDisplayNone())
                return;

            auto w = this->width();
            auto h = this->height();
            if (w.isZero() || h.isZero())
                return;

            LengthContext lengthContext(this);
            auto _x = lengthContext.valueForLength(x(), LengthMode::Width);
            auto _y = lengthContext.valueForLength(y(), LengthMode::Height);
            auto _w = lengthContext.valueForLength(w, LengthMode::Width);
            auto _h = lengthContext.valueForLength(h, LengthMode::Height);

            auto viewBox = this->viewBox();
            auto preserveAspectRatio = this->preserveAspectRatio();
            auto viewTranslation = Transform::translated(_x, _y);
            auto viewTransform = preserveAspectRatio.getMatrix(_w, _h, viewBox);

            auto symbol = make_unique<LayoutSymbol>();
            symbol->width = _w;
            symbol->height = _h;
            symbol->transform = (viewTransform * viewTranslation) * transform();
            symbol->clip = /*isOverflowHidden() ? preserveAspectRatio.getClip(_w, _h, viewBox) :*/ Rect::Invalid;
            symbol->opacity = opacity();
            symbol->masker = nullptr;//context->getMasker(mask());
            symbol->clipper = nullptr;//context->getClipper(clip_path());
            layoutChildren(context, symbol.get());
            current->addChildIfNotEmpty(std::move(symbol));
        }
            std::unique_ptr<Node> clone() const
            {
                return cloneElement<SVGElement>();
            }
    };



    //class ClipPathElement : public GraphicsElement//////
    //{
    //public:
    //    ClipPathElement()
    //        : GraphicsElement(ElementId::ClipPath)
    //    {
    //    }

    //    Units clipPathUnits() const
    //    {
    //        auto& value = get(PropertyId::ClipPathUnits);
    //        return Parser::parseUnits(value, Units::UserSpaceOnUse);
    //    }
    //    std::unique_ptr<LayoutClipPath> getClipper(LayoutContext* context) const
    //    {
    //        if(context->hasReference(this))
    //            return nullptr;

    //        LayoutBreaker layoutBreaker(context, this);
    //        auto clipper = make_unique<LayoutClipPath>();
    //        clipper->units = clipPathUnits();
    //        clipper->transform = transform();
    //        clipper->clipper = context->getClipper(clip_path());
    //        layoutChildren(context, clipper.get());
    //        return clipper;
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<ClipPathElement>();
    //    }
    //};


    //class GradientAttributes////?
    //{
    //public:
    //    GradientAttributes() = default;

    //    const Transform& gradientTransform() const { return m_gradientTransform; }
    //    SpreadMethod spreadMethod() const { return m_spreadMethod; }
    //    Units gradientUnits() const { return m_gradientUnits; }
    //    const GradientStops& gradientStops() const { return m_gradientStops; }

    //    bool hasGradientTransform() const { return m_hasGradientTransform; }
    //    bool hasSpreadMethod() const { return m_hasSpreadMethod; }
    //    bool hasGradientUnits() const { return m_hasGradientUnits; }
    //    bool hasGradientStops() const { return m_hasGradientStops; }

    //    void setGradientTransform(const Transform& gradientTransform)
    //    {
    //        m_gradientTransform = gradientTransform;
    //        m_hasGradientTransform = true;
    //    }

    //    void setSpreadMethod(SpreadMethod spreadMethod)
    //    {
    //        m_spreadMethod = spreadMethod;
    //        m_hasSpreadMethod = true;
    //    }

    //    void setGradientUnits(Units gradientUnits)
    //    {
    //        m_gradientUnits = gradientUnits;
    //        m_hasGradientUnits = true;
    //    }

    //    void setGradientStops(const GradientStops& gradientStops)
    //    {
    //        m_gradientStops = gradientStops;
    //        m_hasGradientStops = gradientStops.size();
    //    }

    //private:
    //    Transform m_gradientTransform;
    //    SpreadMethod m_spreadMethod{SpreadMethod::Pad};
    //    Units m_gradientUnits{Units::ObjectBoundingBox};
    //    GradientStops m_gradientStops;

    //    bool m_hasGradientTransform{false};
    //    bool m_hasSpreadMethod{false};
    //    bool m_hasGradientUnits{false};
    //    bool m_hasGradientStops{false};
    //};

    //class LinearGradientAttributes : public GradientAttributes/////?
    //{
    //public:
    //    LinearGradientAttributes() = default;

    //    const Length& x1() const { return m_x1; }
    //    const Length& y1() const { return m_y1; }
    //    const Length& x2() const { return m_x2; }
    //    const Length& y2() const { return m_y2; }

    //    bool hasX1() const { return m_hasX1; }
    //    bool hasY1() const { return m_hasY1; }
    //    bool hasX2() const { return m_hasX2; }
    //    bool hasY2() const { return m_hasY2; }

    //    void setX1(const Length& x1)
    //    {
    //        m_x1 = x1;
    //        m_hasX1 = true;
    //    }

    //    void setY1(const Length& y1)
    //    {
    //        m_y1 = y1;
    //        m_hasY1 = true;
    //    }

    //    void setX2(const Length& x2)
    //    {
    //        m_x2 = x2;
    //        m_hasX2 = true;
    //    }

    //    void setY2(const Length& y2)
    //    {
    //        m_y2 = y2;
    //        m_hasY2 = true;
    //    }

    //private:
    //    Length m_x1;
    //    Length m_y1;
    //    Length m_x2{100, LengthUnits::Percent};
    //    Length m_y2;

    //    bool m_hasX1{false};
    //    bool m_hasY1{false};
    //    bool m_hasX2{false};
    //    bool m_hasY2{false};
    //};

    //class RadialGradientAttributes : public GradientAttributes///?
    //{
    //public:
    //    RadialGradientAttributes() = default;

    //    const Length& cx() const { return m_cx; }
    //    const Length& cy() const { return m_cy; }
    //    const Length& r() const { return m_r; }
    //    const Length& fx() const { return m_fx; }
    //    const Length& fy() const { return m_fy; }

    //    bool hasCx() const { return m_hasCx; }
    //    bool hasCy() const { return m_hasCy; }
    //    bool hasR() const { return m_hasR; }
    //    bool hasFx() const { return m_hasFx; }
    //    bool hasFy() const { return m_hasFy; }

    //    void setCx(const Length& cx)
    //    {
    //        m_cx = cx;
    //        m_hasCx = true;
    //    }

    //    void setCy(const Length& cy)
    //    {
    //        m_cy = cy;
    //        m_hasCy = true;
    //    }

    //    void setR(const Length& r)
    //    {
    //        m_r = r;
    //        m_hasR = true;
    //    }

    //    void setFx(const Length& fx)
    //    {
    //        m_fx = fx;
    //        m_hasFx = true;
    //    }

    //    void setFy(const Length& fy)
    //    {
    //        m_fy = fy;
    //        m_hasFy = true;
    //    }


    //private:
    //    Length m_cx{50, LengthUnits::Percent};
    //    Length m_cy{50, LengthUnits::Percent};
    //    Length m_r{50, LengthUnits::Percent};
    //    Length m_fx;
    //    Length m_fy;

    //    bool m_hasCx{false};
    //    bool m_hasCy{false};
    //    bool m_hasR{false};
    //    bool m_hasFx{false};
    //    bool m_hasFy{false};
    //};

    //class PatternAttributes///
    //{
    //public:
    //    PatternAttributes() = default;

    //    const Length& x() const { return m_x; }
    //    const Length& y() const { return m_y; }
    //    const Length& width() const { return m_width; }
    //    const Length& height() const { return m_height; }
    //    const Transform& patternTransform() const { return m_patternTransform; }
    //    Units patternUnits() const { return m_patternUnits; }
    //    Units patternContentUnits() const { return m_patternContentUnits; }
    //    const Rect& viewBox() const { return m_viewBox; }
    //    const PreserveAspectRatio& preserveAspectRatio() const { return m_preserveAspectRatio; }
    //    const PatternElement* patternContentElement() const { return m_patternContentElement; }

    //    bool hasX() const { return m_hasX; }
    //    bool hasY() const { return m_hasY; }
    //    bool hasWidth() const { return m_hasWidth; }
    //    bool hasHeight() const { return m_hasHeight; }
    //    bool hasPatternTransform() const { return m_hasPatternTransform; }
    //    bool hasPatternUnits() const { return m_hasPatternUnits; }
    //    bool hasPatternContentUnits() const { return m_hasPatternContentUnits; }
    //    bool hasViewBox() const { return m_hasViewBox; }
    //    bool hasPreserveAspectRatio() const { return m_hasPreserveAspectRatio; }
    //    bool hasPatternContentElement() const { return m_hasPatternContentElement; }

    //    void setX(const Length& x)
    //    {
    //        m_x = x;
    //        m_hasX = true;
    //    }

    //    void setY(const Length& y)
    //    {
    //        m_y = y;
    //        m_hasY = true;
    //    }

    //    void setWidth(const Length& width)
    //    {
    //        m_width = width;
    //        m_hasWidth = true;
    //    }

    //    void setHeight(const Length& height)
    //    {
    //        m_height = height;
    //        m_hasHeight = true;
    //    }

    //    void setPatternTransform(const Transform& patternTransform)
    //    {
    //        m_patternTransform = patternTransform;
    //        m_hasPatternTransform = true;
    //    }

    //    void setPatternUnits(Units patternUnits)
    //    {
    //        m_patternUnits = patternUnits;
    //        m_hasPatternUnits = true;
    //    }

    //    void setPatternContentUnits(Units patternContentUnits)
    //    {
    //        m_patternContentUnits = patternContentUnits;
    //        m_hasPatternContentUnits = true;
    //    }

    //    void setViewBox(const Rect& viewBox)
    //    {
    //        m_viewBox = viewBox;
    //        m_hasViewBox = true;
    //    }

    //    void setPreserveAspectRatio(const PreserveAspectRatio& preserveAspectRatio)
    //    {
    //        m_preserveAspectRatio = preserveAspectRatio;
    //        m_hasPreserveAspectRatio = true;
    //    }

    //    void setPatternContentElement(const PatternElement* patternContentElement)
    //    {
    //        m_patternContentElement = patternContentElement;
    //        m_hasPatternContentElement = true;
    //    }

    //private:
    //    Length m_x;
    //    Length m_y;
    //    Length m_width;
    //    Length m_height;
    //    Transform m_patternTransform;
    //    Units m_patternUnits{Units::ObjectBoundingBox};
    //    Units m_patternContentUnits{Units::UserSpaceOnUse};
    //    Rect m_viewBox{Rect::Invalid};
    //    PreserveAspectRatio m_preserveAspectRatio;
    //    const PatternElement* m_patternContentElement{nullptr};

    //    bool m_hasX{false};
    //    bool m_hasY{false};
    //    bool m_hasWidth{false};
    //    bool m_hasHeight{false};
    //    bool m_hasPatternTransform{false};
    //    bool m_hasPatternUnits{false};
    //    bool m_hasPatternContentUnits{false};
    //    bool m_hasViewBox{false};
    //    bool m_hasPreserveAspectRatio{false};
    //    bool m_hasPatternContentElement{false};
    //};


    //class GradientElement : public PaintElement///?
    //{
    //public:
    //    GradientElement(ElementId id)
    //        : PaintElement(id)
    //    {
    //    }

    //    Transform gradientTransform() const
    //    {
    //        auto& value = get(PropertyId::GradientTransform);
    //        return Parser::parseTransform(value);
    //    }
    //    SpreadMethod spreadMethod() const
    //    {
    //        auto& value = get(PropertyId::SpreadMethod);
    //        return Parser::parseSpreadMethod(value);
    //    }
    //    Units gradientUnits() const
    //    {
    //        auto& value = get(PropertyId::GradientUnits);
    //        return Parser::parseUnits(value, Units::ObjectBoundingBox);
    //    }
    //    std::string href() const
    //    {
    //        auto& value = get(PropertyId::Href);
    //        return Parser::parseHref(value);
    //    }
    //    GradientStops buildGradientStops() const
    //    {
    //        GradientStops gradientStops;
    //        double prevOffset = 0.0;
    //        for(auto& child : children)
    //        {
    //            if(child->isText())
    //                continue;
    //            auto element = static_cast<Element*>(child.get());
    //            if(element->id != ElementId::Stop)
    //                continue;
    //            auto stop = static_cast<StopElement*>(element);
    //            auto offset = std::max(prevOffset, stop->offset());
    //            prevOffset = offset;
    //            gradientStops.emplace_back(offset, stop->stopColorWithOpacity());
    //        }

    //        return gradientStops;
    //    }
    //};

    //class LinearGradientElement : public GradientElement///?
    //{
    //public:
    //    LinearGradientElement()
    //        : GradientElement(ElementId::LinearGradient)
    //    {
    //    }

    //    Length x1() const
    //    {
    //        auto& value = get(PropertyId::X1);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length y1() const
    //    {
    //        auto& value = get(PropertyId::Y1);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length x2() const
    //    {
    //        auto& value = get(PropertyId::X2);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::HundredPercent);
    //    }
    //    Length y2() const
    //    {
    //        auto& value = get(PropertyId::Y2);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }

    //    std::unique_ptr<LayoutObject> getPainter(LayoutContext* context) const
    //    {
    //        LinearGradientAttributes attributes;
    //        std::set<const GradientElement*> processedGradients;
    //        const GradientElement* current = this;

    //        while(true)
    //        {
    //            if(!attributes.hasGradientTransform() && current->has(PropertyId::GradientTransform))
    //                attributes.setGradientTransform(current->gradientTransform());
    //            if(!attributes.hasSpreadMethod() && current->has(PropertyId::SpreadMethod))
    //                attributes.setSpreadMethod(current->spreadMethod());
    //            if(!attributes.hasGradientUnits() && current->has(PropertyId::GradientUnits))
    //                attributes.setGradientUnits(current->gradientUnits());
    //            if(!attributes.hasGradientStops())
    //                attributes.setGradientStops(current->buildGradientStops());

    //            if(current->id == ElementId::LinearGradient)
    //            {
    //                auto element = static_cast<const LinearGradientElement*>(current);
    //                if(!attributes.hasX1() && element->has(PropertyId::X1))
    //                    attributes.setX1(element->x1());
    //                if(!attributes.hasY1() && element->has(PropertyId::Y1))
    //                    attributes.setY1(element->y1());
    //                if(!attributes.hasX2() && element->has(PropertyId::X2))
    //                    attributes.setX2(element->x2());
    //                if(!attributes.hasY2() && element->has(PropertyId::Y2))
    //                    attributes.setY2(element->y2());
    //            }

    //            auto ref = context->getElementById(current->href());
    //            if(!ref || !(ref->id == ElementId::LinearGradient || ref->id == ElementId::RadialGradient))
    //                break;

    //            processedGradients.insert(current);
    //            current = static_cast<const GradientElement*>(ref);
    //            if(processedGradients.find(current) != processedGradients.end())
    //                break;
    //        }

    //        auto& stops = attributes.gradientStops();
    //        if(stops.empty())
    //            return nullptr;

    //        LengthContext lengthContext(this, attributes.gradientUnits());
    //        auto x1 = lengthContext.valueForLength(attributes.x1(), LengthMode::Width);
    //        auto y1 = lengthContext.valueForLength(attributes.y1(), LengthMode::Height);
    //        auto x2 = lengthContext.valueForLength(attributes.x2(), LengthMode::Width);
    //        auto y2 = lengthContext.valueForLength(attributes.y2(), LengthMode::Height);
    //        if((x1 == x2 && y1 == y2) || stops.size() == 1)
    //        {
    //            auto solid = make_unique<LayoutSolidColor>();
    //            solid->color = std::get<1>(stops.back());
    //            return std::move(solid);
    //        }

    //        auto gradient = make_unique<LayoutLinearGradient>();
    //        gradient->transform = attributes.gradientTransform();
    //        gradient->spreadMethod = attributes.spreadMethod();
    //        gradient->units = attributes.gradientUnits();
    //        gradient->stops = attributes.gradientStops();
    //        gradient->x1 = x1;
    //        gradient->y1 = y1;
    //        gradient->x2 = x2;
    //        gradient->y2 = y2;
    //        return std::move(gradient);
    //    }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<LinearGradientElement>();
    //    }
    //};

    //class RadialGradientElement : public GradientElement///?
    //{
    //public:
    //    RadialGradientElement()
    //        : GradientElement(ElementId::RadialGradient)
    //    {
    //    }

    //    Length cx() const
    //    {
    //        auto& value = get(PropertyId::Cx);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::FiftyPercent);
    //    }
    //    Length cy() const
    //    {
    //        auto& value = get(PropertyId::Cy);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::FiftyPercent);
    //    }
    //    Length r() const
    //    {
    //        auto& value = get(PropertyId::R);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::FiftyPercent);
    //    }
    //    Length fx() const
    //    {
    //        auto& value = get(PropertyId::Fx);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length fy() const
    //    {
    //        auto& value = get(PropertyId::Fy);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }

    //    std::unique_ptr<LayoutObject> getPainter(LayoutContext* context) const
    //    {
    //        RadialGradientAttributes attributes;
    //        std::set<const GradientElement*> processedGradients;
    //        const GradientElement* current = this;

    //        while(true)
    //        {
    //            if(!attributes.hasGradientTransform() && current->has(PropertyId::GradientTransform))
    //                attributes.setGradientTransform(current->gradientTransform());
    //            if(!attributes.hasSpreadMethod() && current->has(PropertyId::SpreadMethod))
    //                attributes.setSpreadMethod(current->spreadMethod());
    //            if(!attributes.hasGradientUnits() && current->has(PropertyId::GradientUnits))
    //                attributes.setGradientUnits(current->gradientUnits());
    //            if(!attributes.hasGradientStops())
    //                attributes.setGradientStops(current->buildGradientStops());

    //            if(current->id == ElementId::RadialGradient)
    //            {
    //                auto element = static_cast<const RadialGradientElement*>(current);
    //                if(!attributes.hasCx() && element->has(PropertyId::Cx))
    //                    attributes.setCx(element->cx());
    //                if(!attributes.hasCy() && element->has(PropertyId::Cy))
    //                    attributes.setCy(element->cy());
    //                if(!attributes.hasR() && element->has(PropertyId::R))
    //                    attributes.setR(element->r());
    //                if(!attributes.hasFx() && element->has(PropertyId::Fx))
    //                    attributes.setFx(element->fx());
    //                if(!attributes.hasFy() && element->has(PropertyId::Fy))
    //                    attributes.setFy(element->fy());
    //            }

    //            auto ref = context->getElementById(current->href());
    //            if(!ref || !(ref->id == ElementId::LinearGradient || ref->id == ElementId::RadialGradient))
    //                break;

    //            processedGradients.insert(current);
    //            current = static_cast<const GradientElement*>(ref);
    //            if(processedGradients.find(current) != processedGradients.end())
    //                break;
    //        }

    //        if(!attributes.hasFx())
    //            attributes.setFx(attributes.cx());
    //        if(!attributes.hasFy())
    //            attributes.setFy(attributes.cy());

    //        auto& stops = attributes.gradientStops();
    //        if(stops.empty())
    //            return nullptr;

    //        auto& r = attributes.r();
    //        if(r.isZero() || stops.size() == 1)
    //        {
    //            auto solid = make_unique<LayoutSolidColor>();
    //            solid->color = std::get<1>(stops.back());
    //            return std::move(solid);
    //        }

    //        auto gradient = make_unique<LayoutRadialGradient>();
    //        gradient->transform = attributes.gradientTransform();
    //        gradient->spreadMethod = attributes.spreadMethod();
    //        gradient->units = attributes.gradientUnits();
    //        gradient->stops = attributes.gradientStops();

    //        LengthContext lengthContext(this, attributes.gradientUnits());
    //        gradient->cx = lengthContext.valueForLength(attributes.cx(), LengthMode::Width);
    //        gradient->cy = lengthContext.valueForLength(attributes.cy(), LengthMode::Height);
    //        gradient->r = lengthContext.valueForLength(attributes.r(), LengthMode::Both);
    //        gradient->fx = lengthContext.valueForLength(attributes.fx(), LengthMode::Width);
    //        gradient->fy = lengthContext.valueForLength(attributes.fy(), LengthMode::Height);
    //        return std::move(gradient);
    //    }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<RadialGradientElement>();
    //    }
    //};

    //class PatternElement : public PaintElement///
    //{
    //public:
    //    PatternElement()
    //        : PaintElement(ElementId::Pattern)
    //    {
    //    }

    //    Length x() const
    //    {
    //        auto& value = get(PropertyId::X);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length y() const
    //    {
    //        auto& value = get(PropertyId::Y);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length width() const
    //    {
    //        auto& value = get(PropertyId::Width);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
    //    }
    //    Length height() const
    //    {
    //        auto& value = get(PropertyId::Height);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::Zero);
    //    }
    //    Transform patternTransform() const
    //    {
    //        auto& value = get(PropertyId::PatternTransform);
    //        return Parser::parseTransform(value);
    //    }
    //    Units patternUnits() const
    //    {
    //        auto& value = get(PropertyId::PatternUnits);
    //        return Parser::parseUnits(value, Units::ObjectBoundingBox);
    //    }
    //    Units patternContentUnits() const
    //    {
    //        auto& value = get(PropertyId::PatternContentUnits);
    //        return Parser::parseUnits(value, Units::UserSpaceOnUse);
    //    }

    //    Rect viewBox() const
    //    {
    //        auto& value = get(PropertyId::ViewBox);
    //        return Parser::parseViewBox(value);
    //    }
    //    PreserveAspectRatio preserveAspectRatio() const
    //    {
    //        auto& value = get(PropertyId::PreserveAspectRatio);
    //        return Parser::parsePreserveAspectRatio(value);
    //    }
    //    std::string href() const
    //    {
    //        auto& value = get(PropertyId::Href);
    //        return Parser::parseHref(value);
    //    }

    //    std::unique_ptr<LayoutObject> getPainter(LayoutContext* context) const
    //    {
    //        if(context->hasReference(this))
    //            return nullptr;

    //        PatternAttributes attributes;
    //        std::set<const PatternElement*> processedPatterns;
    //        const PatternElement* current = this;

    //        while(true)
    //        {
    //            if(!attributes.hasX() && current->has(PropertyId::X))
    //                attributes.setX(current->x());
    //            if(!attributes.hasY() && current->has(PropertyId::Y))
    //                attributes.setY(current->y());
    //            if(!attributes.hasWidth() && current->has(PropertyId::Width))
    //                attributes.setWidth(current->width());
    //            if(!attributes.hasHeight() && current->has(PropertyId::Height))
    //                attributes.setHeight(current->height());
    //            if(!attributes.hasPatternTransform() && current->has(PropertyId::PatternTransform))
    //                attributes.setPatternTransform(current->patternTransform());
    //            if(!attributes.hasPatternUnits() && current->has(PropertyId::PatternUnits))
    //                attributes.setPatternUnits(current->patternUnits());
    //            if(!attributes.hasPatternContentUnits() && current->has(PropertyId::PatternContentUnits))
    //                attributes.setPatternContentUnits(current->patternContentUnits());
    //            if(!attributes.hasViewBox() && current->has(PropertyId::ViewBox))
    //                attributes.setViewBox(current->viewBox());
    //            if(!attributes.hasPreserveAspectRatio() && current->has(PropertyId::PreserveAspectRatio))
    //                attributes.setPreserveAspectRatio(current->preserveAspectRatio());
    //            if(!attributes.hasPatternContentElement() && current->children.size())
    //                attributes.setPatternContentElement(current);

    //            auto ref = context->getElementById(current->href());
    //            if(!ref || ref->id != ElementId::Pattern)
    //                break;

    //            processedPatterns.insert(current);
    //            current = static_cast<const PatternElement*>(ref);
    //            if(processedPatterns.find(current) != processedPatterns.end())
    //                break;
    //        }

    //        auto& width = attributes.width();
    //        auto& height = attributes.height();
    //        auto element = attributes.patternContentElement();
    //        if(element == nullptr || width.isZero() || height.isZero())
    //            return nullptr;

    //        LayoutBreaker layoutBreaker(context, this);
    //        auto pattern = make_unique<LayoutPattern>();
    //        pattern->transform = attributes.patternTransform();
    //        pattern->units = attributes.patternUnits();
    //        pattern->contentUnits = attributes.patternContentUnits();
    //        pattern->viewBox = attributes.viewBox();
    //        pattern->preserveAspectRatio = attributes.preserveAspectRatio();

    //        LengthContext lengthContext(this, attributes.patternUnits());
    //        pattern->x = lengthContext.valueForLength(attributes.x(), LengthMode::Width);
    //        pattern->y = lengthContext.valueForLength(attributes.y(), LengthMode::Height);
    //        pattern->width = lengthContext.valueForLength(attributes.width(), LengthMode::Width);
    //        pattern->height = lengthContext.valueForLength(attributes.height(), LengthMode::Height);
    //        element->layoutChildren(context, pattern.get());
    //        return std::move(pattern);
    //    }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<PatternElement>();
    //    }
    //};

    //class SolidColorElement : public PaintElement///
    //{
    //public:
    //    SolidColorElement()
    //        : PaintElement(ElementId::SolidColor)
    //    {
    //    }

    //    std::unique_ptr<LayoutObject> getPainter(LayoutContext*) const
    //    {
    //        auto solid = make_unique<LayoutSolidColor>();
    //        solid->color = solid_color();
    //        solid->color.a = solid_opacity();
    //        return std::move(solid);
    //    }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<SolidColorElement>();
    //    }
    //};





    //class SymbolElement : public StyledElement///
    //{
    //public:
    //    SymbolElement()
    //        : StyledElement(ElementId::Symbol)
    //    {
    //    }

    //    Length x() const
    //    {
    //        auto& value = get(PropertyId::X);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length y() const
    //    {
    //        auto& value = get(PropertyId::Y);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length width() const
    //    {
    //        auto& value = get(PropertyId::Width);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
    //    }
    //    Length height() const
    //    {
    //        auto& value = get(PropertyId::Height);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
    //    }
    //    Rect viewBox() const
    //    {
    //        auto& value = get(PropertyId::ViewBox);
    //        return Parser::parseViewBox(value);
    //    }
    //    PreserveAspectRatio preserveAspectRatio() const
    //    {
    //        auto& value = get(PropertyId::PreserveAspectRatio);
    //        return Parser::parsePreserveAspectRatio(value);
    //    }

    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<SymbolElement>();
    //    }
    //};


    //class UseElement : public GraphicsElement///
    //{
    //public:
    //    UseElement()
    //        : GraphicsElement(ElementId::Use)
    //    {
    //    }

    //    Length x() const
    //    {
    //        auto& value = get(PropertyId::X);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length y() const
    //    {
    //        auto& value = get(PropertyId::Y);
    //        return Parser::parseLength(value, AllowNegativeLengths, Length::Zero);
    //    }
    //    Length width() const
    //    {
    //        auto& value = get(PropertyId::Width);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
    //    }
    //    Length height() const
    //    {
    //        auto& value = get(PropertyId::Height);
    //        return Parser::parseLength(value, ForbidNegativeLengths, Length::HundredPercent);
    //    }
    //    std::string href() const
    //    {
    //        auto& value = get(PropertyId::Href);
    //        return Parser::parseHref(value);
    //    }
    //    void transferWidthAndHeight(Element* element) const
    //    {
    //        auto& width = get(PropertyId::Width);
    //        auto& height = get(PropertyId::Height);

    //        element->set(PropertyId::Width, width, 0x0);
    //        element->set(PropertyId::Height, height, 0x0);
    //    }

    //    void layout(LayoutContext* context, LayoutContainer* current) const
    //    {
    //        if(isDisplayNone())
    //            return;

    //        auto ref = context->getElementById(href());
    //        if(ref == nullptr || context->hasReference(ref) || (current->id == LayoutId::ClipPath && !ref->isGeometry()))
    //            return;

    //        LayoutBreaker layoutBreaker(context, ref);
    //        auto group = make_unique<GElement>();
    //        group->parent = parent;
    //        group->properties = properties;

    //        LengthContext lengthContext(this);
    //        auto _x = lengthContext.valueForLength(x(), LengthMode::Width);
    //        auto _y = lengthContext.valueForLength(y(), LengthMode::Height);

    //        auto transform = get(PropertyId::Transform);
    //        transform += "translate(";
    //        transform += std::to_string(_x);
    //        transform += ' ';
    //        transform += std::to_string(_y);
    //        transform += ')';
    //        group->set(PropertyId::Transform, transform, 0x10);

    //        if(ref->id == ElementId::Svg || ref->id == ElementId::Symbol)
    //        {
    //            auto element = ref->cloneElement<SVGElement>();
    //            transferWidthAndHeight(element.get());
    //            group->addChild(std::move(element));
    //        }
    //        else
    //        {
    //            group->addChild(ref->clone());
    //        }

    //        group->layout(context, current);
    //    }
    //    std::unique_ptr<Node> clone() const
    //    {
    //        return cloneElement<UseElement>();
    //    }
    //};


    static inline std::unique_ptr<Element> createElement(ElementId id)
    {
        switch (id) {
        case ElementId::Svg:
            return make_unique<SVGElement>();
        case ElementId::Path:
            return make_unique<PathElement>();
        case ElementId::G:
            return make_unique<GElement>();
        case ElementId::Rect:
            return make_unique<RectElement>();
        case ElementId::Circle:
            return make_unique<CircleElement>();
            //    case ElementId::Ellipse:
            //        return make_unique<EllipseElement>();
            //    case ElementId::Line:
            //        return make_unique<LineElement>();
            //    case ElementId::Defs:
            //        return make_unique<DefsElement>();
            //    case ElementId::Polygon:
            //        return make_unique<PolygonElement>();
            //    case ElementId::Polyline:
            //        return make_unique<PolylineElement>();
                case ElementId::Stop:
                    return make_unique<StopElement>();
            //    case ElementId::LinearGradient:
            //        return make_unique<LinearGradientElement>();
            //    case ElementId::RadialGradient:
            //        return make_unique<RadialGradientElement>();
            //    case ElementId::Symbol:
            //        return make_unique<SymbolElement>();
            //    case ElementId::Use:
            //        return make_unique<UseElement>();
            //    case ElementId::Pattern:
            //        return make_unique<PatternElement>();
            //    case ElementId::Mask:
            //        return make_unique<MaskElement>();
            //    case ElementId::ClipPath:
            //        return make_unique<ClipPathElement>();
            //    case ElementId::SolidColor:
            //        return make_unique<SolidColorElement>();
            //    case ElementId::Marker:
            //        return make_unique<MarkerElement>();
            //    case ElementId::Style:
            //        return make_unique<StyleElement>();
        default: {
            printf("ElementId unknown");
            break;
        }
        }

        return nullptr;
    }

    struct THtml
    {
        struct TProp {
            std::string    Name;
            std::string    Value;
        };
        struct TItem
        {
        public:
            std::string    Name;
            //int       iNotClosed;   //if the tag doesn't require to close
            TProp* Props;
            TItem* SubTags;
            //variant   Classes;
            //variant   Text;         //a string or an string array, if the text is divided by other html elements
            //TItem     Parent;
            //int       iNotClose;
            int   Tag;          //the storage for external operations
        };
        //protected:
        //    TStringOP StrOP;
        //    int       cntEmpty;
    public:
        TItem* HierArr;
        //TItem*     CurElm;
        TItem* Body;
        //    TProp*     CurProp;
        //    int       iTextInside;
        //    int       iPrintMode;
        //    int       iScript;         //==1 was <script , ==2 was <script>, without src
        //    int       iHyphen;         //1 -, 2--, 3-->
        //    int       EndTag;
        //    int       cntInsTag;       //after <
        //    int       cntWasName;      //after <Tag
        //    int       cntWasPropName;  //after <Tag Prop
        //    int       cntWasClass;     //after <Tag class
        //    int       cntMustBeValue;  //after <Tag Prop=
        //    int       cntSQuote;
        //    int       cntDQuote;
        //    int       cntSkip;
        //    int       cntExclam;       //after <!
        //    int       cntHyphen;       //after <!-
        //    int       cntHyphen2;      //after <!-- .... -
        //    int       cntScript;
        //    int       cntWasPropName2; //after <meta http-
        //    int       cntCmntDoctype;  //<!DOCTYPE html
        //    variant   ProcObj;
        //    std::string    OnMatch;
        int       iType;           //1 - svg
    };

    class ParseDocument
    {
    public:
        ParseDocument()
        {
        }
        ~ParseDocument()
        {
        }


        bool elastParse(THtml* svg)
        {
            Element* current = nullptr;
            std::string name;
            svg->iType == 1 ? name = "svg" : name = "";
            std::string value;
            int ignoring = 0;

            //        auto remove_comments = [](std::string& value) {
            //            auto start = value.find("/*");
            //            while(start != std::string::npos) {
            //                auto end = value.find("*/", start + 2);
            //                value.erase(start, end - start + 2);
            //                start = value.find("/*");
            //            }
            //        };

            //        auto handle_text = [&](const char* start, const char* end, bool in_cdata) {
            //            if(ignoring > 0 || current == nullptr || current->id != ElementId::Style)
            //                return;
            //            printf("handle_text");

            ////            if(in_cdata)
            ////                value.assign(start, end);
            ////            else
            ////                decodeText(start, end, value);

            ////            remove_comments(value);
            //            //cssparser.parseMore(value);
            //        };
            int iBody = 0;
            while (true)
            {
                //            auto start = ptr;
                //            if(!Utils::skipUntil(ptr, end, '<'))
                //                break;

                //            //handle_text(start, ptr, false);
                //            ptr += 1;

                //            if(ptr < end && *ptr == '/')
                //            {
                //                if(current == nullptr && ignoring == 0)
                //                    return false;

                //                ++ptr;
                //                if(!readIdentifier(ptr, end, name))
                //                    return false;

                //                if(ptr >= end || *ptr != '>')
                //                    return false;

                //                if(ignoring > 0)
                //                    --ignoring;
                //                else
                //                    current = current->parent;

                //                ++ptr;
                //                continue;
                //            }

                //            if(ptr < end && *ptr == '?')
                //            {
                //                ++ptr;
                //                if(!readIdentifier(ptr, end, name))
                //                    return false;

                //                if(!Utils::skipUntil(ptr, end, "?>"))
                //                    return false;

                //                ptr += 2;
                //                continue;
                //            }

                //            if(ptr < end && *ptr == '!')
                //            {
                //                ++ptr;
                //                if(Utils::skipDesc(ptr, end, "--"))
                //                {
                //                    start = ptr;
                //                    if(!Utils::skipUntil(ptr, end, "-->"))
                //                        return false;

                //                    handle_text(start, ptr, false);
                //                    ptr += 3;
                //                    continue;
                //                }

                //                if(Utils::skipDesc(ptr, end, "[CDATA["))
                //                {
                //                    start = ptr;
                //                    if(!Utils::skipUntil(ptr, end, "]]>"))
                //                        return false;

                //                    handle_text(start, ptr, true);
                //                    ptr += 3;
                //                    continue;
                //                }

                //                if(Utils::skipDesc(ptr, end, "DOCTYPE"))
                //                {
                //                    while(ptr < end && *ptr != '>')
                //                    {
                //                        if(*ptr == '[')
                //                        {
                //                            ++ptr;
                //                            int depth = 1;
                //                            while(ptr < end && depth > 0)
                //                            {
                //                                if(*ptr == '[') ++depth;
                //                                else if(*ptr == ']') --depth;
                //                                ++ptr;
                //                            }
                //                        }
                //                        else
                //                        {
                //                            ++ptr;
                //                        }
                //                    }

                //                    if(ptr >= end || *ptr != '>')
                //                        return false;

                //                    ptr += 1;
                //                    continue;
                //                }

                //                return false;
                //            }

                //            if(!readIdentifier(ptr, end, name))
                //                return false;

                auto id = ignoring == 0 ? elementId(name) : ElementId::Unknown;
                if (id == ElementId::Unknown)
                    ++ignoring;
                if (id == ElementId::G) { //убрать для поддержки групп
                    iBody++;
                    name = svg->Body->SubTags[iBody].Name;
                    continue;
                }

                Element* element = nullptr;
                THtml::TItem* curItem;
                int sizeElem = 0;
                if (ignoring == 0)
                {
                    if (m_rootElement && current == nullptr)
                        return false;

                    if (m_rootElement == nullptr)
                    {
                        if (id != ElementId::Svg)
                            return false;

                        m_rootElement = make_unique<SVGElement>();
                        element = m_rootElement.get();
                        current = element; //убрать для поддержки групп
                        sizeElem = svg->HierArr->Tag;
                        if (!sizeElem)
                            return false;
                        curItem = svg->HierArr;
                    }
                    else
                    {
                        auto child = createElement(id);
                        element = child.get();
                        current->addChild(std::move(child));
                        sizeElem = svg->Body->SubTags[iBody].Tag;
                        if (!sizeElem /*&& id != ElementId::G*/)
                            return false;
                        curItem = &svg->Body->SubTags[iBody];
                        iBody++;
                    }
                }

                //Utils::skipWs(ptr, end);
                for (int i = 0; i < sizeElem; i++)
                {
                    name = curItem->Props[i].Name;
                    //                Utils::skipWs(ptr, end);
                    //                if(ptr >= end || *ptr != '=')
                    //                    return false;
                    //                ++ptr;

                    //                Utils::skipWs(ptr, end);
                    //                if(ptr >= end || !(*ptr == '\"' || *ptr == '\''))
                    //                    return false;

                    //                auto quote = *ptr;
                    //                ++ptr;
                    //                Utils::skipWs(ptr, end);
                    //                start = ptr;
                    //                while(ptr < end && *ptr != quote)
                    //                    ++ptr;

                    //                if(ptr >= end || *ptr != quote)
                    //                    return false;

                    auto id = element ? propertyId(name) : PropertyId::Unknown;
                    if (id != PropertyId::Unknown)
                    {
                        //decodeText(start, Utils::rtrim(start, ptr), value);
                        if (id == PropertyId::Style)
                        {
                            //remove_comments(value);
                            //parseStyle(value, element);
                        }
                        else
                        {
                            if (id == PropertyId::Id)
                                m_idCache.emplace(curItem->Props[i].Value, element);
                            element->set(id, curItem->Props[i].Value, 0x1);
                        }
                    }
                    //                ++ptr;
                    //                Utils::skipWs(ptr, end);
                }
                if (iBody == svg->Body->Tag)
                    break;

                //ignoring = 0;
                name = svg->Body->SubTags[iBody].Name;

                if (false/*ptr < end && *ptr == '>'*/) //ветка для поддержки групп.
                {

                    if (element != nullptr)
                        current = element;

                    //                ++ptr;
                    continue;
                }

                if (true/*ptr < end && *ptr == '/'*/)
                {
                    //                ++ptr;
                    //                if(ptr >= end || *ptr != '>')
                    //                    return false;

                    if (ignoring > 0)
                        --ignoring;

                    //                ++ptr;
                    continue;
                }

                //            return false;
            }

            //        if(!m_rootElement || ptr < end || ignoring > 0)
            //            return false;

            //        const auto& rules = cssparser.rules();
            //        if(!rules.empty())
            //        {
            ////            RuleMatchContext context(rules);
            ////            m_rootElement->transverse([&context](Node* node) {
            ////                if(node->isText())
            ////                    return false;

            ////                auto element = static_cast<Element*>(node);
            ////                auto declarations = context.match(element);
            ////                for(auto& declaration : declarations)
            ////                    element->properties.add(*declaration);
            ////                return false;
            ////            });
            //        }

            return true;
        }

            bool parse(const char* data, std::size_t size)
            {
                auto ptr = data;
                auto end = ptr + size;

                //CSSParser cssparser;
                Element* current = nullptr;
                std::string name;
                std::string value;
                int ignoring = 0;

                auto remove_comments = [](std::string& value) {
                    auto start = value.find("/*");
                    while(start != std::string::npos) {
                        auto end = value.find("*/", start + 2);
                        value.erase(start, end - start + 2);
                        start = value.find("/*");
                    }
                };

                auto handle_text = [&](const char* start, const char* end, bool in_cdata) {
                    if(ignoring > 0 || current == nullptr || current->id != ElementId::Style)
                        return;
                    printf("handle_text");

        //            if(in_cdata)
        //                value.assign(start, end);
        //            else
        //                decodeText(start, end, value);

        //            remove_comments(value);
                    //cssparser.parseMore(value);
                };

                while(ptr < end)
                {
                    auto start = ptr;
                    if(!Utils::skipUntil(ptr, end, '<'))
                        break;

                    handle_text(start, ptr, false);
                    ptr += 1;

                    if(ptr < end && *ptr == '/')
                    {
                        if(current == nullptr && ignoring == 0)
                            return false;

                        ++ptr;
                        if(!readIdentifier(ptr, end, name))
                            return false;

                        if(ptr >= end || *ptr != '>')
                            return false;

                        if(ignoring > 0)
                            --ignoring;
                        else
                            current = current->parent;

                        ++ptr;
                        continue;
                    }

                    if(ptr < end && *ptr == '?')
                    {
                        ++ptr;
                        if(!readIdentifier(ptr, end, name))
                            return false;

                        if(!Utils::skipUntil(ptr, end, "?>"))
                            return false;

                        ptr += 2;
                        continue;
                    }

                    if(ptr < end && *ptr == '!')
                    {
                        ++ptr;
                        if(Utils::skipDesc(ptr, end, "--"))
                        {
                            start = ptr;
                            if(!Utils::skipUntil(ptr, end, "-->"))
                                return false;

                            handle_text(start, ptr, false);
                            ptr += 3;
                            continue;
                        }

                        if(Utils::skipDesc(ptr, end, "[CDATA["))
                        {
                            start = ptr;
                            if(!Utils::skipUntil(ptr, end, "]]>"))
                                return false;

                            handle_text(start, ptr, true);
                            ptr += 3;
                            continue;
                        }

                        if(Utils::skipDesc(ptr, end, "DOCTYPE"))
                        {
                            while(ptr < end && *ptr != '>')
                            {
                                if(*ptr == '[')
                                {
                                    ++ptr;
                                    int depth = 1;
                                    while(ptr < end && depth > 0)
                                    {
                                        if(*ptr == '[') ++depth;
                                        else if(*ptr == ']') --depth;
                                        ++ptr;
                                    }
                                }
                                else
                                {
                                    ++ptr;
                                }
                            }

                            if(ptr >= end || *ptr != '>')
                                return false;

                            ptr += 1;
                            continue;
                        }

                        return false;
                    }

                    if(!readIdentifier(ptr, end, name))
                        return false;

                    auto id = ignoring == 0 ? elementId(name) : ElementId::Unknown;
                    if(id == ElementId::Unknown)
                        ++ignoring;

                    Element* element = nullptr;
                    if(ignoring == 0)
                    {
                        if(m_rootElement && current == nullptr)
                            return false;

                        if(m_rootElement == nullptr)
                        {
                            if(id != ElementId::Svg)
                                return false;

                            m_rootElement = make_unique<SVGElement>();
                            element = m_rootElement.get();
                        }
                        else
                        {
                            auto child = createElement(id);
                            element = child.get();
                            current->addChild(std::move(child));
                        }
                    }

                    Utils::skipWs(ptr, end);
                    while(ptr < end && readIdentifier(ptr, end, name))
                    {
                        Utils::skipWs(ptr, end);
                        if(ptr >= end || *ptr != '=')
                            return false;
                        ++ptr;

                        Utils::skipWs(ptr, end);
                        if(ptr >= end || !(*ptr == '\"' || *ptr == '\''))
                            return false;

                        auto quote = *ptr;
                        ++ptr;
                        Utils::skipWs(ptr, end);
                        start = ptr;
                        while(ptr < end && *ptr != quote)
                            ++ptr;

                        if(ptr >= end || *ptr != quote)
                            return false;

                        auto id = element ? propertyId(name) : PropertyId::Unknown;
                        if(id != PropertyId::Unknown)
                        {
                            decodeText(start, Utils::rtrim(start, ptr), value);
                            if(id == PropertyId::Style)
                            {
                                remove_comments(value);
                                //parseStyle(value, element);
                            }
                            else
                            {
                                if(id == PropertyId::Id)
                                    m_idCache.emplace(value, element);
                                element->set(id, value, 0x1);
                            }
                        }

                        ++ptr;
                        Utils::skipWs(ptr, end);
                    }

                    if(ptr < end && *ptr == '>')
                    {
                        if(element != nullptr)
                            current = element;

                        ++ptr;
                        continue;
                    }

                    if(ptr < end && *ptr == '/')
                    {
                        ++ptr;
                        if(ptr >= end || *ptr != '>')
                            return false;

                        if(ignoring > 0)
                            --ignoring;

                        ++ptr;
                        continue;
                    }

                    return false;
                }

                if(!m_rootElement || ptr < end || ignoring > 0)
                    return false;

        //        const auto& rules = cssparser.rules();
        //        if(!rules.empty())
        //        {
        ////            RuleMatchContext context(rules);
        ////            m_rootElement->transverse([&context](Node* node) {
        ////                if(node->isText())
        ////                    return false;

        ////                auto element = static_cast<Element*>(node);
        ////                auto declarations = context.match(element);
        ////                for(auto& declaration : declarations)
        ////                    element->properties.add(*declaration);
        ////                return false;
        ////            });
        //        }

                return true;
            }

        SVGElement* rootElement() const { return m_rootElement.get(); }
        Element* getElementById(const std::string& id) const
        {
            auto it = m_idCache.find(id);
            if (it == m_idCache.end())
                return nullptr;

            return it->second;
        }
        std::unique_ptr<LayoutSymbol> layout() const
        {
            return m_rootElement->layoutDocument(this);
        }

    private:
        std::unique_ptr<SVGElement> m_rootElement;
        std::map<std::string, Element*> m_idCache;
    };

    Element* LayoutContext::getElementById(const std::string& id) const
    {
        return m_document->getElementById(id);
    }

    //LayoutClipPath *LayoutContext::getClipper(const std::string &id)
    //{
    //    if(id.empty())
    //        return nullptr;

    //    auto ref = getResourcesById(id);///////////
    //    if(ref && ref->id == LayoutId::ClipPath)
    //        return static_cast<LayoutClipPath*>(ref);

    //    auto element = getElementById(id);
    //    if(element == nullptr || element->id != ElementId::ClipPath)
    //        return nullptr;

    //    auto clipper = static_cast<ClipPathElement*>(element)->getClipper(this);
    //    return static_cast<LayoutClipPath*>(addToResourcesCache(id, std::move(clipper)));
    //}

    //Rect Element::currentViewport() const///
    //{
    //    if(parent == nullptr)
    //    {
    //        auto element = static_cast<const SVGElement*>(this);
    //        if(element->has(PropertyId::ViewBox))
    //            return element->viewBox();
    //        return Rect{0, 0, 512, 512};
    //    }

    //    if(parent->id == ElementId::Svg)
    //    {
    //        auto element = static_cast<SVGElement*>(parent);
    //        if(element->has(PropertyId::ViewBox))
    //            return element->viewBox();

    //        LengthContext lengthContext(element);
    //        auto _x = lengthContext.valueForLength(element->x(), LengthMode::Width);
    //        auto _y = lengthContext.valueForLength(element->y(), LengthMode::Height);
    //        auto _w = lengthContext.valueForLength(element->width(), LengthMode::Width);
    //        auto _h = lengthContext.valueForLength(element->height(), LengthMode::Height);
    //        return Rect{_x, _y, _w, _h};
    //    }

    //    return parent->currentViewport();
    //}


    class Box
    {
    public:
        Box() = default;
        Box(double x, double y, double w, double h)
            : x(x), y(y), w(w), h(h)
        {}

    public:
        double x{ 0 };
        double y{ 0 };
        double w{ 0 };
        double h{ 0 };
    };

    class Matrix
    {
    public:
        Matrix() = default;
        Matrix(double a, double b, double c, double d, double e, double f)
            : a(a), b(b), c(c), d(d), e(e), f(f)
        {}

    public:
        double a{ 1 };
        double b{ 0 };
        double c{ 0 };
        double d{ 1 };
        double e{ 0 };
        double f{ 0 };
    };

    class LUNASVG_API Bitmap
    {
    public:
        /**
         * @note Default bitmap format is RGBA (non-premultiplied).
         */
        Bitmap()
        {
        }
        Bitmap(std::uint8_t* data, std::uint32_t width, std::uint32_t height, std::uint32_t stride)
            : m_impl(new Impl(data, width, height, stride))
        {
        }
        Bitmap(std::uint32_t width, std::uint32_t height)
            : m_impl(new Impl(width, height))
        {
        }
        //void convert(int ri, int gi, int bi, int ai, bool unpremultiply);
        void convertToRGBA() { convert(0, 1, 2, 3, true); }

        void convert(int ri, int gi, int bi, int ai, bool unpremultiply)
        {
            auto width = this->width();
            auto height = this->height();
            auto stride = this->stride();
            auto rowData = this->data();

            for (std::uint32_t y = 0; y < height; y++)
            {
                auto data = rowData;
                for (std::uint32_t x = 0; x < width; x++)
                {
                    auto b = data[0];
                    auto g = data[1];
                    auto r = data[2];
                    auto a = data[3];

                    if (unpremultiply && a != 0)
                    {
                        r = (r * 255) / a;
                        g = (g * 255) / a;
                        b = (b * 255) / a;
                    }

                    data[ri] = r;
                    data[gi] = g;
                    data[bi] = b;
                    data[ai] = a;
                    data += 4;
                }
                rowData += stride;
            }
        }


        void reset(std::uint8_t* data, std::uint32_t width, std::uint32_t height, std::uint32_t stride)
        {
            m_impl.reset(new Impl(data, width, height, stride));
        }
        void reset(std::uint32_t width, std::uint32_t height)
        {
            m_impl.reset(new Impl(width, height));
        }

        std::uint8_t* data() const
        {
            return m_impl ? m_impl->data ? m_impl->data : m_impl->ownData.get() : nullptr;
        }
        std::uint32_t width() const
        {
            return m_impl ? m_impl->width : 0;
        }
        std::uint32_t height() const
        {
            return m_impl ? m_impl->height : 0;
        }
        std::uint32_t stride() const
        {
            return m_impl ? m_impl->stride : 0;
        }
        bool valid() const
        {
            return !!m_impl;
        }

    private:
        struct Impl
        {
            Impl(std::uint8_t* data, std::uint32_t width, std::uint32_t height, std::uint32_t stride)
                : data(data), width(width), height(height), stride(stride)
            {
            }
            Impl(std::uint32_t width, std::uint32_t height)
                : ownData(new std::uint8_t[width * height * 4]), data(nullptr), width(width), height(height), stride(width * 4)
            {
            }

            std::unique_ptr<std::uint8_t[]> ownData;
            std::uint8_t* data;
            std::uint32_t width;
            std::uint32_t height;
            std::uint32_t stride;
        };
        std::shared_ptr<Impl> m_impl;
    };


    class LUNASVG_API Document
    {
    public:
        /**
         * @brief Creates a document from a file
         * @param filename - file to load
         * @return pointer to document on success, otherwise nullptr
         */
             static std::unique_ptr<Document> loadFromFile(const std::string& filename)
             {
                 std::ifstream fs;
                 fs.open(filename);
                 if(!fs.is_open())
                     return nullptr;

                 std::string content;
                 std::getline(fs, content, '\0');
                 fs.close();

                 return loadFromData(content);
             }

             /**
              * @brief Creates a document from a string
              * @param string - string to load
              * @return pointer to document on success, otherwise nullptr
              */
             static std::unique_ptr<Document> loadFromData(const std::string& string)
             {
                 return loadFromData(string.data(), string.size());
             }

             /**
              * @brief Creates a document from a string data and size
              * @param data - string data to load
              * @param size - size of the data to load, in bytes
              * @return pointer to document on success, otherwise nullptr
              */
             static std::unique_ptr<Document> loadFromData(const char* data, std::size_t size)
             {
                 ParseDocument parser;
                 if(!parser.parse(data, size))
                     return nullptr;

                 auto root = parser.layout();
                 if(!root || root->children.empty())
                     return nullptr;

                 std::unique_ptr<Document> document(new Document);
                 document->root = std::move(root);
                 return document;
             }

         //    /**
         //     * @brief Creates a document from a null terminated string data
         //     * @param data - null terminated string data to load
         //     * @return pointer to document on success, otherwise nullptr
         //     */
         //    static std::unique_ptr<Document> loadFromData(const char* data)
         //    {
         //        return loadFromData(data, std::strlen(data));
         //    }

             /**
              * @brief Rotates the document matrix clockwise around the current origin
              * @param angle - rotation angle, in degrees
              * @return this
              */
              //    Document* rotate(double angle)/////->
              //    {
              //        root->transform.rotate(angle);
              //        return this;
              //    }

              //    /**
              //     * @brief Rotates the document matrix clockwise around the given point
              //     * @param angle - rotation angle, in degrees
              //     * @param cx - horizontal translation
              //     * @param cy - vertical translation
              //     * @return this
              //     */
              //    Document* rotate(double angle, double cx, double cy)
              //    {
              //        root->transform.rotate(angle, cx, cy);
              //        return this;
              //    }

              //    /**
              //     * @brief Scales the document matrix by sx horizontally and sy vertically
              //     * @param sx - horizontal scale factor
              //     * @param sy - vertical scale factor
              //     * @return this
              //     */
              //    Document* scale(double sx, double sy)
              //    {
              //        root->transform.scale(sx, sy);
              //        return this;
              //    }

              //    /**
              //     * @brief Shears the document matrix by shx horizontally and shy vertically
              //     * @param shx - horizontal skew factor, in degree
              //     * @param shy - vertical skew factor, in degree
              //     * @return this
              //     */
              //    Document* shear(double shx, double shy)
              //    {
              //        root->transform.shear(shx, shy);
              //        return this;
              //    }

              //    /**
              //     * @brief Translates the document matrix by tx horizontally and ty vertically
              //     * @param tx - horizontal translation
              //     * @param ty - vertical translation
              //     * @return this
              //     */
              //    Document* translate(double tx, double ty)
              //    {
              //        root->transform.translate(tx, ty);
              //        return this;
              //    }

              //    /**
              //     * @brief Multiplies the document matrix by Matrix(a, b, c, d, e, f)
              //     * @param a - horizontal scale factor
              //     * @param b - horizontal skew factor
              //     * @param c - vertical skew factor
              //     * @param d - vertical scale factor
              //     * @param e - horizontal translation
              //     * @param f - vertical translation
              //     * @return this
              //     */
              //    Document* transform(double a, double b, double c, double d, double e, double f)
              //    {
              //        root->transform.transform(a, b, c, d, e, f);
              //        return this;
              //    }

                  /**
                   * @brief Resets the document matrix to identity
                   * @return this
                   */
                   //    Document* identity()
                   //    {
                   //        root->transform.identity();
                   //        return this;
                   //    }

                       /**
                        * @brief Returns the current transformation matrix of the document
                        * @return the current transformation matrix
                        */
                        //    Matrix matrix() const
                        //    {
                        //        Matrix matrix;
                        //        matrix.a = root->transform.m00;
                        //        matrix.b = root->transform.m10;
                        //        matrix.c = root->transform.m01;
                        //        matrix.d = root->transform.m11;
                        //        matrix.e = root->transform.m02;
                        //        matrix.f = root->transform.m12;
                        //        return matrix;
                        //    }

                            /**
                             * @brief Returns the smallest rectangle in which the document fits
                             * @return the smallest rectangle in which the document fits
                             */
                             //    Box box() const
                             //    {
                             //        auto box = root->map(root->strokeBoundingBox());
                             //        return Box{box.x, box.y, box.w, box.h};
                             //    }

                                 /**
                                  * @brief Returns width of the document
                                  * @return the width of the document in pixels
                                  */
                                  //    double width() const
                                  //    {
                                  //        return root->width;
                                  //    }

                                  //    /**
                                  //     * @brief Returns the height of the document
                                  //     * @return the height of the document in pixels
                                  //     */
                                  //    double height() const
                                  //    {
                                  //        return root->height;
                                  //    }

                                      /**
                                       * @brief Renders the document to a bitmap
                                       * @param matrix - the current transformation matrix
                                       * @param bitmap - target image on which the content will be drawn
                                       * @param backgroundColor - background color in 0xRRGGBBAA format
                                       */
        void render(Bitmap bitmap, const Matrix& matrix = Matrix{}, std::uint32_t backgroundColor = 0x00000000) const
        {
            RenderState state(nullptr, RenderMode::Display);
            state.canvas = Canvas::create(bitmap.data(), bitmap.width(), bitmap.height(), bitmap.stride());
            state.transform = Transform(matrix.a, matrix.b, matrix.c, matrix.d, matrix.e, matrix.f);
            state.canvas->clear(backgroundColor);
            root->render(state);
            state.canvas->rgba();
        }

        /**
         * @brief Renders the document to a bitmap
         * @param width - maximum width, in pixels
         * @param height - maximum height, in pixels
         * @param backgroundColor - background color in 0xRRGGBBAA format
         * @return the raster representation of the document
         */
        Bitmap renderToBitmap(std::uint32_t width = 0, std::uint32_t height = 0, std::uint32_t backgroundColor = 0x00000000) const
        {
          //  printf("aaa=%d", root->width);
            if (root->width == 0.0 || root->height == 0.0)
                return Bitmap{};

            if (width == 0 && height == 0)
            {
                width = static_cast<std::uint32_t>(std::ceil(root->width));
                height = static_cast<std::uint32_t>(std::ceil(root->height));
            }
            else if (width != 0 && height == 0)
            {
                height = static_cast<std::uint32_t>(std::ceil(width * root->height / root->width));
            }
            else if (height != 0 && width == 0)
            {
                width = static_cast<std::uint32_t>(std::ceil(height * root->width / root->height));
            }

            Bitmap bitmap{ width, height };
            Matrix matrix{ width / root->width, 0, 0, height / root->height, 0, 0 };
            render(bitmap, matrix, backgroundColor);

            return bitmap;
        }

        ~Document()
        {
        }
        //private:
        Document()
        {
        }

        std::unique_ptr<LayoutSymbol> root;
    };


//} //namespace lunasvg

#endif // LUNASVG_H

//////////////////////////// SO -> Elastic transport ////////////////////
//#ifdef _WIN
//#include <windows.h>
//#else
//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
#define V_SVG_API extern "C"
    typedef uint64_t EL_UINT;
//#end
    typedef struct Binary_Methods_STRUC {
        char* Name;
        void                  (*Method)(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg);
    }Binary_Methods_STRUC;
    typedef struct ELAST_FUNC {
        char* Name;
        void    (*Func)();
    }ELAST_FUNC;
    typedef EL_UINT(*GetFuncOffFT)(EL_UINT* Body, char* FuncName);
    typedef EL_UINT(*CallFuncFT)(EL_UINT* Body, EL_UINT  FileInd, EL_UINT Off, EL_UINT** Parms, EL_UINT ParmCount);
    typedef EL_UINT(*GetFileIndFT)();
    typedef EL_UINT* (*ConstructProc)();
    GetFuncOffFT GetFuncOff;
    CallFuncFT   CallFuncOff;
    GetFileIndFT GetFileIndOff;
    //static Bitmap bitmap;
    // Class V_SVG for transoport renderToBitmapSO to Elastic
    class V_SVG : public Bitmap {
    public:
        V_SVG();
        EL_UINT          FileInd;
        EL_UINT* Body;
        EL_UINT          GetInitialNumberOff;
        EL_UINT          bIs2;
        //Bitmap  renderToBitmap(std::uint32_t width = 0, std::uint32_t height = 0, std::uint32_t backgroundColor = 0x00000000);
         //void render(Bitmap bitmap, const Matrix& matrix = Matrix{}, std::uint32_t backgroundColor = 0x00000000) const;
        void renderToBitmapSO(EL_UINT* buf, char* filename, EL_UINT Len, EL_UINT width = 0, EL_UINT height = 0, EL_UINT backgroundColor = 0x00000000) {
 

            //ParseDocument parser;
            //parser.elastParse(svg);
            //Document document;
            auto document = Document::loadFromFile(filename);
            auto bitmap = document->renderToBitmap(width, height, backgroundColor);
            

 
            //auto root = make_unique<LayoutSymbol>();
            //root->width = width;
            //root->height = height;

//            document.root = root;//parser.layout();

            bitmap.convertToRGBA();
         /*   printf("filename:  %s\n", filename);
            printf("width:  %d\n", bitmap.width());
            printf("height:  %d\n", bitmap.height());
            printf("backgroundColor:  %d\n", backgroundColor);*/

            //const void* data = bitmap.data();

           // printf("data p so %p\n", document);
           // printf("data p so %d\n", document);
            //printf("data p so %s\n", typeid(document).name());

           // printf("bmw:  %d\n", bitmap.width());
            //printf("data p so %p\n", buf);
            memmove(buf, bitmap.data(), width * height * 4);
            //printf("data p so %p\n", buf);
            //buf = bitmap.data();

            //printf("data p so %p\n", buf);
            //printf("data p so %d\n", buf);
            //printf("data p so %s\n", typeid(buf).name());


            //char datafs = (char)bitmap.data();
            //printf("bufsize:  %d\n", sizeof(width * height * 4));

            //printf("data p so %p\n", data);
            //printf("data p so %d\n", data);
            //printf("data p so %s\n", typeid(data).name());

            //printf("size w x so: %d x %d \n", int(bitmap.width()), int(bitmap.height()));

            //buf = malloc(int(bitmap.width()) * int(bitmap.height()) * 4);

            //buf = data;

           // stbi_write_png("test_png_from_h.png", int(bitmap.width()), int(bitmap.height()), 4, (const void*)buf, 0);

            // if (!document)  printf ("Error svg document. Filename : %s",filename); 
        }
        //EL_UINT   Print(char* Str, EL_UINT Len) {
        //    printf("the string: %s, of length: %d, is test2: %d\n", Str, Len, bIs2);
        //}
        //EL_UINT   Print2(EL_UINT D1, EL_UINT D2) {
        //    EL_UINT D3 = 0;
        //    if (GetInitialNumberOff != NULL && GetInitialNumberOff != -1) {
        //        D3 = CallFuncOff(Body, FileInd, GetInitialNumberOff, 0, 0);
        //    }
        //    printf("the sum is %d\n", D1 + D2 + D3 + bIs2);
        //}
    };

    void V_SVG_Init(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
    {
        V_SVG* Class;
        EL_UINT* Ptr;
        EL_UINT* Body;
        Body = (EL_UINT*)Adr[2];
        Class = (V_SVG*)Adr[2][2];
        Class->Body = Body;
        Class->GetInitialNumberOff = GetFuncOff(Body, "GetInitialNumber");
        Class->FileInd = GetFileIndOff();
    }
    void V_SVG_renderToBitmapSO(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
    {
        V_SVG* Class;
        EL_UINT* Ptr;
        EL_UINT* Ptr1;
        EL_UINT* Ptr2;
        EL_UINT* Ptr3;
        EL_UINT* Ptr4;
        Class = (V_SVG*)Adr[2][2];
        Ptr = (EL_UINT*)Adr[4 + 0];
        Ptr1 = (EL_UINT*)Adr[4 + 1];
        Ptr2 = (EL_UINT*)Adr[4 + 2];
        Ptr3 = (EL_UINT*)Adr[4 + 3];
        Ptr4 = (EL_UINT*)Adr[4 + 4];

        Class->renderToBitmapSO((EL_UINT*)Ptr[0], (char*)Ptr1[1], Ptr1[0], Ptr2[0], Ptr3[0], Ptr4[0]);

    }
    //void V_SVG_Test1(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
    //{
    //    V_Test* Class;
    //    EL_UINT* Ptr;
    //    Class = (V_Test*)Adr[2][2];
    //    Ptr = (EL_UINT*)Adr[4 + 0];
    //    Class->Print((char*)Ptr[1], Ptr[0]);
    //
    //}
    //void V_Test_Test2(EL_UINT** Adr, EL_UINT NumOfOpr, EL_UINT* DataSeg)
    //{
    //    V_Test* Class;
    //    EL_UINT* Ptr;
    //    EL_UINT* Ptr2;
    //    Class = (V_Test*)Adr[2][2];
    //    Ptr = (EL_UINT*)Adr[4 + 0];
    //    Ptr2 = (EL_UINT*)Adr[4 + 1];
    //    Class->Print2(Ptr[0], Ptr2[0]);
    //}
    Binary_Methods_STRUC V_SVG_STRUC_Methods[] =
    {
        "int Init", &V_SVG_Init,
        //    "int Test1 string ptr", &V_Test_Test1,
        //    "int Test2 int ptr int ptr", &V_Test_Test2,
            "int renderToBitmapSO m_ptr ptr string ptr int ptr int ptr int ptr",&V_SVG_renderToBitmapSO,
            NULL
    };
    //Binary_Methods_STRUC V_Test2_STRUC_Methods[] =
    //{
    //    "int Init", &V_Test_Init,
    //    "int Test1 string ptr", &V_Test_Test1,
    //    "int Test2 int ptr int ptr", &V_Test_Test2,
    //    NULL
    //};
    Binary_Methods_STRUC* MethodStrucTable[] = {
    V_SVG_STRUC_Methods,
    //V_Test2_STRUC_Methods,
    NULL
    };

    const char* Tbl[] = { "V_SVG" };
    V_SVG::V_SVG() {
        GetInitialNumberOff = 0;
        //bIs2 = false;
    }
    EL_UINT* V_SVG_Construct()
    {
        V_SVG* SVGTrans;
        SVGTrans = new V_SVG;
        return (EL_UINT*)SVGTrans;
    }
    //EL_UINT* V_Test2_Construct()
    //{
    //
    //    V_Test* Test;
    //    Test = new V_Test;
    //    Test->bIs2 = true;
    //    printf("bIs2 = true\n");
    //    return (EL_UINT*)Test;
    //}
    //
    V_SVG_API Binary_Methods_STRUC** Init(const char*** Names, ELAST_FUNC* FuncTable) {
        Names[0] = Tbl;
        for (int i = 0; ; i++) {
            if (FuncTable[i].Name == NULL)break;
            if (strcmp(FuncTable[i].Name, "GetFuncOff") == 0) {
                GetFuncOff = (GetFuncOffFT)FuncTable[i].Func;
            }
            else if (strcmp(FuncTable[i].Name, "CallFunc") == 0) {
                CallFuncOff = (CallFuncFT)FuncTable[i].Func;
            }
            else if (strcmp(FuncTable[i].Name, "GetFileInd") == 0) {
                GetFileIndOff = (GetFileIndFT)FuncTable[i].Func;
            }

        }
        return MethodStrucTable;
    }



    V_SVG_API ConstructProc GetConstructor(EL_UINT i) {
        if (i == 0)return V_SVG_Construct;
        /*return V_Test2_Construct;*/
    }

    //////////////////////////// SO -> Elastic transport ////////////////////

//    int main() {
//       return 0;
//    }