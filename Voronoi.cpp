#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define EPS 0.00001
#include <vector>
#include "Voronoi.h"
#include "methods.h"
int Voronoi::voronoi()
{
    ofstream out("voron.txt");
    ofstream outf("field.txt");
    ofstream outt("tri.txt");
    vector<Point> main; main.emplace_back(-1, -1); main.emplace_back(-1, 1); main.emplace_back(1, 1); main.emplace_back(1, -1);
    for (int i = 0; i < point_.size(); ++i)
    {
        Poly pol(main);
        for (int j = 0; j < point_.size(); ++j)
        {
            if (j != i)
            {
                Line l = sp(point_[j], point_[i]);
                Hplane p(l, point_[i]);
                pol = sec(pol, p);
                // cout << "( "<<i<<","<< j<<" ) " << "\n";
            }
        }
        for (int k = 0; k < pol.q; ++k)
            out << pol.point_[k].x_ << "  " << pol.point_[k].y_ << "\n";
        out << pol.point_[0].x_ << "  " << pol.point_[0].y_ << "\n";
        out << "\n";
        out << "\n";
        for (int k = 0; k < pol.q - 1; ++k)
        {
            for (int j = 0; j < point_.size(); ++j)
            {
                if (j != i)
                {
                    Line l = sp(point_[j], point_[i]);
                    if (fabs(l.k - (pol.point_[k + 1].y_ - pol.point_[k].y_) / (pol.point_[k + 1].x_ - pol.point_[k].x_)) < EPS)
                    {

                        outt << point_[i].x_ << "  " << point_[i].y_ << "\n";
                        outt << point_[j].x_ << "  " << point_[j].y_ << "\n";
                        outt << "\n" << "\n";
                    }
                }
            }
        }
        for (int j = 0; j < point_.size(); ++j)
        {
            if (j != i)
            {
                Line l = sp(point_[j], point_[i]);
                if (fabs(l.k - (pol.point_[0].y_ - pol.point_[pol.q - 1].y_) / (pol.point_[0].x_ - pol.point_[pol.q - 1].x_)) < EPS)
                {
                    outt << point_[i].x_ << "  " << point_[i].y_ << "\n";
                    outt << point_[j].x_ << "  " << point_[j].y_ << "\n";
                    outt << "\n" << "\n";
                }
            }
        }
        //pol.point_.emplace_back(-1, -1); pol.point_.emplace_back(-1, 1); pol.point_.emplace_back(1, 1); pol.point_.emplace_back(1, -1);
    }
    for (int i = 0; i < point_.size(); ++i)
        outf << point_[i].x_ << "  " << point_[i].y_ << "\n";
    out.close();
    outf.close();
    outt.close();
    cout << fabs(-1);
    return 0;
};
int Voronoi::field(vector<Point> p)
{
    for (int j = 0; j < p.size(); ++j)
        point_.push_back(p[j]);
    return 0;
}