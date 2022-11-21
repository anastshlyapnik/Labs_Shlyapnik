#pragma once
class checking
{
    template <typename T>
    T NumberChecking(T min, T max) {
        T x;
        while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
            cout << "Wrong request! Please input numeric value more than " << min << " and less than " << max << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        return x;
    }
    template <typename T>
    ostream& operator<< (ostream& out, unordered_map <int, T>& p) {
        out << "Exiting id: ";
        for (auto& [i, obj] : p) {
            out << i << " ";
        }
        out << endl;
        return out;
    }

    template <typename T>
    using filter_p = bool (*) (Pipe& p, T par);
    template <typename T>
    using filter_cs = bool(*) (CS& cs, T par);
    template <typename T>
    vector <int> search_p_by_parametr(unordered_map <int, Pipe>& pipe_group, filter_p<T> f, T par) {
        vector <int> id;
        for (auto& pipe : pipe_group) {
            if (f(pipe.second, par))
                id.push_back(pipe.second.get_id());
        }
        return id;
    }
    template <typename T>
    vector <int> search_cs_by_parametr(unordered_map <int, CS>& cs_group, filter_cs<T> f, T par) {
        vector <int> id;
        for (auto& cs : cs_group) {
            if (f(cs.second, par))
                id.push_back(cs.second.get_id());
        }
        return id;
    }
};

