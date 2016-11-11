(function(b, a) {
    if (typeof module === "object" && typeof module.exports === "object") {
        module.exports = b.document ? a(b, true) : function(c) {
            if (!c.document) {
                throw new Error("jQuery requires a window with a document")
            }
            return a(c)
        }
    } else {
        a(b)
    }
} (typeof window !== "undefined" ? window: this,
function(a3, at) {
    var aN = [];
    var N = aN.slice;
    var ax = aN.concat;
    var w = aN.push;
    var bR = aN.indexOf;
    var aa = {};
    var x = aa.toString;
    var I = aa.hasOwnProperty;
    var C = {};
    var ag = "1.11.1",
    bF = function(e, i) {
        return new bF.fn.init(e, i)
    },
    D = /^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g,
    bP = /^-ms-/,
    aU = /-([\da-z])/gi,
    M = function(e, i) {
        return i.toUpperCase()
    };
    bF.fn = bF.prototype = {
        jquery: ag,
        constructor: bF,
        selector: "",
        length: 0,
        toArray: function() {
            return N.call(this)
        },
        get: function(e) {
            return e != null ? (e < 0 ? this[e + this.length] : this[e]) : N.call(this)
        },
        pushStack: function(e) {
            var i = bF.merge(this.constructor(), e);
            i.prevObject = this;
            i.context = this.context;
            return i
        },
        each: function(i, e) {
            return bF.each(this, i, e)
        },
        map: function(e) {
            return this.pushStack(bF.map(this,
            function(b4, b3) {
                return e.call(b4, b3, b4)
            }))
        },
        slice: function() {
            return this.pushStack(N.apply(this, arguments))
        },
        first: function() {
            return this.eq(0)
        },
        last: function() {
            return this.eq( - 1)
        },
        eq: function(b4) {
            var e = this.length,
            b3 = +b4 + (b4 < 0 ? e: 0);
            return this.pushStack(b3 >= 0 && b3 < e ? [this[b3]] : [])
        },
        end: function() {
            return this.prevObject || this.constructor(null)
        },
        push: w,
        sort: aN.sort,
        splice: aN.splice
    };
    bF.extend = bF.fn.extend = function() {
        var e, b8, b3, b4, cb, b9, b7 = arguments[0] || {},
        b6 = 1,
        b5 = arguments.length,
        ca = false;
        if (typeof b7 === "boolean") {
            ca = b7;
            b7 = arguments[b6] || {};
            b6++
        }
        if (typeof b7 !== "object" && !bF.isFunction(b7)) {
            b7 = {}
        }
        if (b6 === b5) {
            b7 = this;
            b6--
        }
        for (; b6 < b5; b6++) {
            if ((cb = arguments[b6]) != null) {
                for (b4 in cb) {
                    e = b7[b4];
                    b3 = cb[b4];
                    if (b7 === b3) {
                        continue
                    }
                    if (ca && b3 && (bF.isPlainObject(b3) || (b8 = bF.isArray(b3)))) {
                        if (b8) {
                            b8 = false;
                            b9 = e && bF.isArray(e) ? e: []
                        } else {
                            b9 = e && bF.isPlainObject(e) ? e: {}
                        }
                        b7[b4] = bF.extend(ca, b9, b3)
                    } else {
                        if (b3 !== undefined) {
                            b7[b4] = b3
                        }
                    }
                }
            }
        }
        return b7
    };
    bF.extend({
        expando: "jQuery" + (ag + Math.random()).replace(/\D/g, ""),
        isReady: true,
        error: function(e) {
            throw new Error(e)
        },
        noop: function() {},
        isFunction: function(e) {
            return bF.type(e) === "function"
        },
        isArray: Array.isArray ||
        function(e) {
            return bF.type(e) === "array"
        },
        isWindow: function(e) {
            return e != null && e == e.window
        },
        isNumeric: function(e) {
            return ! bF.isArray(e) && e - parseFloat(e) >= 0
        },
        isEmptyObject: function(i) {
            var e;
            for (e in i) {
                return false
            }
            return true
        },
        isPlainObject: function(b4) {
            var i;
            if (!b4 || bF.type(b4) !== "object" || b4.nodeType || bF.isWindow(b4)) {
                return false
            }
            try {
                if (b4.constructor && !I.call(b4, "constructor") && !I.call(b4.constructor.prototype, "isPrototypeOf")) {
                    return false
                }
            } catch(b3) {
                return false
            }
            if (C.ownLast) {
                for (i in b4) {
                    return I.call(b4, i)
                }
            }
            for (i in b4) {}
            return i === undefined || I.call(b4, i)
        },
        type: function(e) {
            if (e == null) {
                return e + ""
            }
            return typeof e === "object" || typeof e === "function" ? aa[x.call(e)] || "object": typeof e
        },
        globalEval: function(e) {
            if (e && bF.trim(e)) { (a3.execScript ||
                function(i) {
                    a3["eval"].call(a3, i)
                })(e)
            }
        },
        camelCase: function(e) {
            return e.replace(bP, "ms-").replace(aU, M)
        },
        nodeName: function(i, e) {
            return i.nodeName && i.nodeName.toLowerCase() === e.toLowerCase()
        },
        each: function(b7, b8, b3) {
            var b6, b4 = 0,
            b5 = b7.length,
            e = ab(b7);
            if (b3) {
                if (e) {
                    for (; b4 < b5; b4++) {
                        b6 = b8.apply(b7[b4], b3);
                        if (b6 === false) {
                            break
                        }
                    }
                } else {
                    for (b4 in b7) {
                        b6 = b8.apply(b7[b4], b3);
                        if (b6 === false) {
                            break
                        }
                    }
                }
            } else {
                if (e) {
                    for (; b4 < b5; b4++) {
                        b6 = b8.call(b7[b4], b4, b7[b4]);
                        if (b6 === false) {
                            break
                        }
                    }
                } else {
                    for (b4 in b7) {
                        b6 = b8.call(b7[b4], b4, b7[b4]);
                        if (b6 === false) {
                            break
                        }
                    }
                }
            }
            return b7
        },
        trim: function(e) {
            return e == null ? "": (e + "").replace(D, "")
        },
        makeArray: function(e, b3) {
            var i = b3 || [];
            if (e != null) {
                if (ab(Object(e))) {
                    bF.merge(i, typeof e === "string" ? [e] : e)
                } else {
                    w.call(i, e)
                }
            }
            return i
        },
        inArray: function(b5, b3, b4) {
            var e;
            if (b3) {
                if (bR) {
                    return bR.call(b3, b5, b4)
                }
                e = b3.length;
                b4 = b4 ? b4 < 0 ? Math.max(0, e + b4) : b4: 0;
                for (; b4 < e; b4++) {
                    if (b4 in b3 && b3[b4] === b5) {
                        return b4
                    }
                }
            }
            return - 1
        },
        merge: function(b6, b4) {
            var e = +b4.length,
            b3 = 0,
            b5 = b6.length;
            while (b3 < e) {
                b6[b5++] = b4[b3++]
            }
            if (e !== e) {
                while (b4[b3] !== undefined) {
                    b6[b5++] = b4[b3++]
                }
            }
            b6.length = b5;
            return b6
        },
        grep: function(e, b9, b6) {
            var b8, b5 = [],
            b3 = 0,
            b4 = e.length,
            b7 = !b6;
            for (; b3 < b4; b3++) {
                b8 = !b9(e[b3], b3);
                if (b8 !== b7) {
                    b5.push(e[b3])
                }
            }
            return b5
        },
        map: function(b4, b9, e) {
            var b8, b6 = 0,
            b7 = b4.length,
            b3 = ab(b4),
            b5 = [];
            if (b3) {
                for (; b6 < b7; b6++) {
                    b8 = b9(b4[b6], b6, e);
                    if (b8 != null) {
                        b5.push(b8)
                    }
                }
            } else {
                for (b6 in b4) {
                    b8 = b9(b4[b6], b6, e);
                    if (b8 != null) {
                        b5.push(b8)
                    }
                }
            }
            return ax.apply([], b5)
        },
        guid: 1,
        proxy: function(b5, b4) {
            var e, b3, i;
            if (typeof b4 === "string") {
                i = b5[b4];
                b4 = b5;
                b5 = i
            }
            if (!bF.isFunction(b5)) {
                return undefined
            }
            e = N.call(arguments, 2);
            b3 = function() {
                return b5.apply(b4 || this, e.concat(N.call(arguments)))
            };
            b3.guid = b5.guid = b5.guid || bF.guid++;
            return b3
        },
        now: function() {
            return + (new Date())
        },
        support: C
    });
    bF.each("Boolean Number String Function Array Date RegExp Object Error".split(" "),
    function(b3, e) {
        aa["[object " + e + "]"] = e.toLowerCase()
    });
    function ab(b3) {
        var i = b3.length,
        e = bF.type(b3);
        if (e === "function" || bF.isWindow(b3)) {
            return false
        }
        if (b3.nodeType === 1 && i) {
            return true
        }
        return e === "array" || i === 0 || typeof i === "number" && i > 0 && (i - 1) in b3
    }
    var m = (function(db) {
        var cu, de, ck, cD, cG, ce, cS, dd, di, cE, cT, cV, cy, cl, c4, cZ, dc, cb, cB, c6 = "sizzle" + -(new Date()),
        cF = db.document,
        df = 0,
        c0 = 0,
        b6 = cw(),
        c5 = cw(),
        cC = cw(),
        cA = function(i, e) {
            if (i === e) {
                cT = true
            }
            return 0
        },
        da = typeof undefined,
        cM = 1 << 31,
        cK = ({}).hasOwnProperty,
        c8 = [],
        c9 = c8.pop,
        cI = c8.push,
        b4 = c8.push,
        cj = c8.slice,
        ca = c8.indexOf ||
        function(dk) {
            var dj = 0,
            e = this.length;
            for (; dj < e; dj++) {
                if (this[dj] === dk) {
                    return dj
                }
            }
            return - 1
        },
        b5 = "checked|selected|async|autofocus|autoplay|controls|defer|disabled|hidden|ismap|loop|multiple|open|readonly|required|scoped",
        cm = "[\\x20\\t\\r\\n\\f]",
        b3 = "(?:\\\\.|[\\w-]|[^\\x00-\\xa0])+",
        cH = b3.replace("w", "w#"),
        c2 = "\\[" + cm + "*(" + b3 + ")(?:" + cm + "*([*^$|!~]?=)" + cm + "*(?:'((?:\\\\.|[^\\\\'])*)'|\"((?:\\\\.|[^\\\\\"])*)\"|(" + cH + "))|)" + cm + "*\\]",
        ch = ":(" + b3 + ")(?:\\((('((?:\\\\.|[^\\\\'])*)'|\"((?:\\\\.|[^\\\\\"])*)\")|((?:\\\\.|[^\\\\()[\\]]|" + c2 + ")*)|.*)\\)|)",
        co = new RegExp("^" + cm + "+|((?:^|[^\\\\])(?:\\\\.)*)" + cm + "+$", "g"),
        cr = new RegExp("^" + cm + "*," + cm + "*"),
        cx = new RegExp("^" + cm + "*([>+~]|" + cm + ")" + cm + "*"),
        cq = new RegExp("=" + cm + "*([^\\]'\"]*?)" + cm + "*\\]", "g"),
        cO = new RegExp(ch),
        cQ = new RegExp("^" + cH + "$"),
        cY = {
            ID: new RegExp("^#(" + b3 + ")"),
            CLASS: new RegExp("^\\.(" + b3 + ")"),
            TAG: new RegExp("^(" + b3.replace("w", "w*") + ")"),
            ATTR: new RegExp("^" + c2),
            PSEUDO: new RegExp("^" + ch),
            CHILD: new RegExp("^:(only|first|last|nth|nth-last)-(child|of-type)(?:\\(" + cm + "*(even|odd|(([+-]|)(\\d*)n|)" + cm + "*(?:([+-]|)" + cm + "*(\\d+)|))" + cm + "*\\)|)", "i"),
            bool: new RegExp("^(?:" + b5 + ")$", "i"),
            needsContext: new RegExp("^" + cm + "*[>+~]|:(even|odd|eq|gt|lt|nth|first|last)(?:\\(" + cm + "*((?:-\\d)?\\d*)" + cm + "*\\)|)(?=[^-]|$)", "i")
        },
        b9 = /^(?:input|select|textarea|button)$/i,
        ci = /^h\d$/i,
        cL = /^[^{]+\{\s*\[native \w/,
        cN = /^(?:#([\w-]+)|(\w+)|\.([\w-]+))$/,
        cX = /[+~]/,
        cJ = /'|\\/g,
        cp = new RegExp("\\\\([\\da-f]{1,6}" + cm + "?|(" + cm + ")|.)", "ig"),
        c1 = function(e, dk, i) {
            var dj = "0x" + dk - 65536;
            return dj !== dj || i ? dk: dj < 0 ? String.fromCharCode(dj + 65536) : String.fromCharCode(dj >> 10 | 55296, dj & 1023 | 56320)
        };
        try {
            b4.apply((c8 = cj.call(cF.childNodes)), cF.childNodes);
            c8[cF.childNodes.length].nodeType
        } catch(cz) {
            b4 = {
                apply: c8.length ?
                function(i, e) {
                    cI.apply(i, cj.call(e))
                }: function(dl, dk) {
                    var e = dl.length,
                    dj = 0;
                    while ((dl[e++] = dk[dj++])) {}
                    dl.length = e - 1
                }
            }
        }
        function cs(dr, dj, dv, dx) {
            var dw, dn, dp, dt, du, dm, dl, e, dk, ds;
            if ((dj ? dj.ownerDocument || dj: cF) !== cy) {
                cV(dj)
            }
            dj = dj || cy;
            dv = dv || [];
            if (!dr || typeof dr !== "string") {
                return dv
            }
            if ((dt = dj.nodeType) !== 1 && dt !== 9) {
                return []
            }
            if (c4 && !dx) {
                if ((dw = cN.exec(dr))) {
                    if ((dp = dw[1])) {
                        if (dt === 9) {
                            dn = dj.getElementById(dp);
                            if (dn && dn.parentNode) {
                                if (dn.id === dp) {
                                    dv.push(dn);
                                    return dv
                                }
                            } else {
                                return dv
                            }
                        } else {
                            if (dj.ownerDocument && (dn = dj.ownerDocument.getElementById(dp)) && cB(dj, dn) && dn.id === dp) {
                                dv.push(dn);
                                return dv
                            }
                        }
                    } else {
                        if (dw[2]) {
                            b4.apply(dv, dj.getElementsByTagName(dr));
                            return dv
                        } else {
                            if ((dp = dw[3]) && de.getElementsByClassName && dj.getElementsByClassName) {
                                b4.apply(dv, dj.getElementsByClassName(dp));
                                return dv
                            }
                        }
                    }
                }
                if (de.qsa && (!cZ || !cZ.test(dr))) {
                    e = dl = c6;
                    dk = dj;
                    ds = dt === 9 && dr;
                    if (dt === 1 && dj.nodeName.toLowerCase() !== "object") {
                        dm = ce(dr);
                        if ((dl = dj.getAttribute("id"))) {
                            e = dl.replace(cJ, "\\$&")
                        } else {
                            dj.setAttribute("id", e)
                        }
                        e = "[id='" + e + "'] ";
                        du = dm.length;
                        while (du--) {
                            dm[du] = e + cf(dm[du])
                        }
                        dk = cX.test(dr) && cP(dj.parentNode) || dj;
                        ds = dm.join(",")
                    }
                    if (ds) {
                        try {
                            b4.apply(dv, dk.querySelectorAll(ds));
                            return dv
                        } catch(dq) {} finally {
                            if (!dl) {
                                dj.removeAttribute("id")
                            }
                        }
                    }
                }
            }
            return dd(dr.replace(co, "$1"), dj, dv, dx)
        }
        function cw() {
            var i = [];
            function e(dj, dk) {
                if (i.push(dj + " ") > ck.cacheLength) {
                    delete e[i.shift()]
                }
                return (e[dj + " "] = dk)
            }
            return e
        }
        function cg(e) {
            e[c6] = true;
            return e
        }
        function cc(i) {
            var dk = cy.createElement("div");
            try {
                return !! i(dk)
            } catch(dj) {
                return false
            } finally {
                if (dk.parentNode) {
                    dk.parentNode.removeChild(dk)
                }
                dk = null
            }
        }
        function dg(dj, dl) {
            var e = dj.split("|"),
            dk = dj.length;
            while (dk--) {
                ck.attrHandle[e[dk]] = dl
            }
        }
        function b7(i, e) {
            var dk = e && i,
            dj = dk && i.nodeType === 1 && e.nodeType === 1 && (~e.sourceIndex || cM) - (~i.sourceIndex || cM);
            if (dj) {
                return dj
            }
            if (dk) {
                while ((dk = dk.nextSibling)) {
                    if (dk === e) {
                        return - 1
                    }
                }
            }
            return i ? 1 : -1
        }
        function ct(e) {
            return function(dj) {
                var i = dj.nodeName.toLowerCase();
                return i === "input" && dj.type === e
            }
        }
        function b8(e) {
            return function(dj) {
                var i = dj.nodeName.toLowerCase();
                return (i === "input" || i === "button") && dj.type === e
            }
        }
        function c3(e) {
            return cg(function(i) {
                i = +i;
                return cg(function(dj, dn) {
                    var dl, dk = e([], dj.length, i),
                    dm = dk.length;
                    while (dm--) {
                        if (dj[(dl = dk[dm])]) {
                            dj[dl] = !(dn[dl] = dj[dl])
                        }
                    }
                })
            })
        }
        function cP(e) {
            return e && typeof e.getElementsByTagName !== da && e
        }
        de = cs.support = {};
        cG = cs.isXML = function(e) {
            var i = e && (e.ownerDocument || e).documentElement;
            return i ? i.nodeName !== "HTML": false
        };
        cV = cs.setDocument = function(dj) {
            var e, dk = dj ? dj.ownerDocument || dj: cF,
            i = dk.defaultView;
            if (dk === cy || dk.nodeType !== 9 || !dk.documentElement) {
                return cy
            }
            cy = dk;
            cl = dk.documentElement;
            c4 = !cG(dk);
            if (i && i !== i.top) {
                if (i.addEventListener) {
                    i.addEventListener("unload",
                    function() {
                        cV()
                    },
                    false)
                } else {
                    if (i.attachEvent) {
                        i.attachEvent("onunload",
                        function() {
                            cV()
                        })
                    }
                }
            }
            de.attributes = cc(function(dl) {
                dl.className = "i";
                return ! dl.getAttribute("className")
            });
            de.getElementsByTagName = cc(function(dl) {
                dl.appendChild(dk.createComment(""));
                return ! dl.getElementsByTagName("*").length
            });
            de.getElementsByClassName = cL.test(dk.getElementsByClassName) && cc(function(dl) {
                dl.innerHTML = "<div class='a'></div><div class='a i'></div>";
                dl.firstChild.className = "i";
                return dl.getElementsByClassName("i").length === 2
            });
            de.getById = cc(function(dl) {
                cl.appendChild(dl).id = c6;
                return ! dk.getElementsByName || !dk.getElementsByName(c6).length
            });
            if (de.getById) {
                ck.find.ID = function(dn, dm) {
                    if (typeof dm.getElementById !== da && c4) {
                        var dl = dm.getElementById(dn);
                        return dl && dl.parentNode ? [dl] : []
                    }
                };
                ck.filter.ID = function(dm) {
                    var dl = dm.replace(cp, c1);
                    return function(dn) {
                        return dn.getAttribute("id") === dl
                    }
                }
            } else {
                delete ck.find.ID;
                ck.filter.ID = function(dm) {
                    var dl = dm.replace(cp, c1);
                    return function(dp) {
                        var dn = typeof dp.getAttributeNode !== da && dp.getAttributeNode("id");
                        return dn && dn.value === dl
                    }
                }
            }
            ck.find.TAG = de.getElementsByTagName ?
            function(dl, dm) {
                if (typeof dm.getElementsByTagName !== da) {
                    return dm.getElementsByTagName(dl)
                }
            }: function(dl, dq) {
                var dr, dp = [],
                dn = 0,
                dm = dq.getElementsByTagName(dl);
                if (dl === "*") {
                    while ((dr = dm[dn++])) {
                        if (dr.nodeType === 1) {
                            dp.push(dr)
                        }
                    }
                    return dp
                }
                return dm
            };
            ck.find.CLASS = de.getElementsByClassName &&
            function(dm, dl) {
                if (typeof dl.getElementsByClassName !== da && c4) {
                    return dl.getElementsByClassName(dm)
                }
            };
            dc = [];
            cZ = [];
            if ((de.qsa = cL.test(dk.querySelectorAll))) {
                cc(function(dl) {
                    dl.innerHTML = "<select msallowclip=''><option selected=''></option></select>";
                    if (dl.querySelectorAll("[msallowclip^='']").length) {
                        cZ.push("[*^$]=" + cm + "*(?:''|\"\")")
                    }
                    if (!dl.querySelectorAll("[selected]").length) {
                        cZ.push("\\[" + cm + "*(?:value|" + b5 + ")")
                    }
                    if (!dl.querySelectorAll(":checked").length) {
                        cZ.push(":checked")
                    }
                });
                cc(function(dm) {
                    var dl = dk.createElement("input");
                    dl.setAttribute("type", "hidden");
                    dm.appendChild(dl).setAttribute("name", "D");
                    if (dm.querySelectorAll("[name=d]").length) {
                        cZ.push("name" + cm + "*[*^$|!~]?=")
                    }
                    if (!dm.querySelectorAll(":enabled").length) {
                        cZ.push(":enabled", ":disabled")
                    }
                    dm.querySelectorAll("*,:x");
                    cZ.push(",.*:")
                })
            }
            if ((de.matchesSelector = cL.test((cb = cl.matches || cl.webkitMatchesSelector || cl.mozMatchesSelector || cl.oMatchesSelector || cl.msMatchesSelector)))) {
                cc(function(dl) {
                    de.disconnectedMatch = cb.call(dl, "div");
                    cb.call(dl, "[s!='']:x");
                    dc.push("!=", ch)
                })
            }
            cZ = cZ.length && new RegExp(cZ.join("|"));
            dc = dc.length && new RegExp(dc.join("|"));
            e = cL.test(cl.compareDocumentPosition);
            cB = e || cL.test(cl.contains) ?
            function(dm, dl) {
                var dp = dm.nodeType === 9 ? dm.documentElement: dm,
                dn = dl && dl.parentNode;
                return dm === dn || !!(dn && dn.nodeType === 1 && (dp.contains ? dp.contains(dn) : dm.compareDocumentPosition && dm.compareDocumentPosition(dn) & 16))
            }: function(dm, dl) {
                if (dl) {
                    while ((dl = dl.parentNode)) {
                        if (dl === dm) {
                            return true
                        }
                    }
                }
                return false
            };
            cA = e ?
            function(dm, dl) {
                if (dm === dl) {
                    cT = true;
                    return 0
                }
                var dn = !dm.compareDocumentPosition - !dl.compareDocumentPosition;
                if (dn) {
                    return dn
                }
                dn = (dm.ownerDocument || dm) === (dl.ownerDocument || dl) ? dm.compareDocumentPosition(dl) : 1;
                if (dn & 1 || (!de.sortDetached && dl.compareDocumentPosition(dm) === dn)) {
                    if (dm === dk || dm.ownerDocument === cF && cB(cF, dm)) {
                        return - 1
                    }
                    if (dl === dk || dl.ownerDocument === cF && cB(cF, dl)) {
                        return 1
                    }
                    return cE ? (ca.call(cE, dm) - ca.call(cE, dl)) : 0
                }
                return dn & 4 ? -1 : 1
            }: function(dm, dl) {
                if (dm === dl) {
                    cT = true;
                    return 0
                }
                var dt, dq = 0,
                ds = dm.parentNode,
                dp = dl.parentNode,
                dn = [dm],
                dr = [dl];
                if (!ds || !dp) {
                    return dm === dk ? -1 : dl === dk ? 1 : ds ? -1 : dp ? 1 : cE ? (ca.call(cE, dm) - ca.call(cE, dl)) : 0
                } else {
                    if (ds === dp) {
                        return b7(dm, dl)
                    }
                }
                dt = dm;
                while ((dt = dt.parentNode)) {
                    dn.unshift(dt)
                }
                dt = dl;
                while ((dt = dt.parentNode)) {
                    dr.unshift(dt)
                }
                while (dn[dq] === dr[dq]) {
                    dq++
                }
                return dq ? b7(dn[dq], dr[dq]) : dn[dq] === cF ? -1 : dr[dq] === cF ? 1 : 0
            };
            return dk
        };
        cs.matches = function(i, e) {
            return cs(i, null, null, e)
        };
        cs.matchesSelector = function(dj, dl) {
            if ((dj.ownerDocument || dj) !== cy) {
                cV(dj)
            }
            dl = dl.replace(cq, "='$1']");
            if (de.matchesSelector && c4 && (!dc || !dc.test(dl)) && (!cZ || !cZ.test(dl))) {
                try {
                    var i = cb.call(dj, dl);
                    if (i || de.disconnectedMatch || dj.document && dj.document.nodeType !== 11) {
                        return i
                    }
                } catch(dk) {}
            }
            return cs(dl, cy, null, [dj]).length > 0
        };
        cs.contains = function(e, i) {
            if ((e.ownerDocument || e) !== cy) {
                cV(e)
            }
            return cB(e, i)
        };
        cs.attr = function(dj, e) {
            if ((dj.ownerDocument || dj) !== cy) {
                cV(dj)
            }
            var i = ck.attrHandle[e.toLowerCase()],
            dk = i && cK.call(ck.attrHandle, e.toLowerCase()) ? i(dj, e, !c4) : undefined;
            return dk !== undefined ? dk: de.attributes || !c4 ? dj.getAttribute(e) : (dk = dj.getAttributeNode(e)) && dk.specified ? dk.value: null
        };
        cs.error = function(e) {
            throw new Error("Syntax error, unrecognized expression: " + e)
        };
        cs.uniqueSort = function(dk) {
            var dl, dm = [],
            e = 0,
            dj = 0;
            cT = !de.detectDuplicates;
            cE = !de.sortStable && dk.slice(0);
            dk.sort(cA);
            if (cT) {
                while ((dl = dk[dj++])) {
                    if (dl === dk[dj]) {
                        e = dm.push(dj)
                    }
                }
                while (e--) {
                    dk.splice(dm[e], 1)
                }
            }
            cE = null;
            return dk
        };
        cD = cs.getText = function(dm) {
            var dl, dj = "",
            dk = 0,
            e = dm.nodeType;
            if (!e) {
                while ((dl = dm[dk++])) {
                    dj += cD(dl)
                }
            } else {
                if (e === 1 || e === 9 || e === 11) {
                    if (typeof dm.textContent === "string") {
                        return dm.textContent
                    } else {
                        for (dm = dm.firstChild; dm; dm = dm.nextSibling) {
                            dj += cD(dm)
                        }
                    }
                } else {
                    if (e === 3 || e === 4) {
                        return dm.nodeValue
                    }
                }
            }
            return dj
        };
        ck = cs.selectors = {
            cacheLength: 50,
            createPseudo: cg,
            match: cY,
            attrHandle: {},
            find: {},
            relative: {
                ">": {
                    dir: "parentNode",
                    first: true
                },
                " ": {
                    dir: "parentNode"
                },
                "+": {
                    dir: "previousSibling",
                    first: true
                },
                "~": {
                    dir: "previousSibling"
                }
            },
            preFilter: {
                ATTR: function(e) {
                    e[1] = e[1].replace(cp, c1);
                    e[3] = (e[3] || e[4] || e[5] || "").replace(cp, c1);
                    if (e[2] === "~=") {
                        e[3] = " " + e[3] + " "
                    }
                    return e.slice(0, 4)
                },
                CHILD: function(e) {
                    e[1] = e[1].toLowerCase();
                    if (e[1].slice(0, 3) === "nth") {
                        if (!e[3]) {
                            cs.error(e[0])
                        }
                        e[4] = +(e[4] ? e[5] + (e[6] || 1) : 2 * (e[3] === "even" || e[3] === "odd"));
                        e[5] = +((e[7] + e[8]) || e[3] === "odd")
                    } else {
                        if (e[3]) {
                            cs.error(e[0])
                        }
                    }
                    return e
                },
                PSEUDO: function(i) {
                    var e, dj = !i[6] && i[2];
                    if (cY.CHILD.test(i[0])) {
                        return null
                    }
                    if (i[3]) {
                        i[2] = i[4] || i[5] || ""
                    } else {
                        if (dj && cO.test(dj) && (e = ce(dj, true)) && (e = dj.indexOf(")", dj.length - e) - dj.length)) {
                            i[0] = i[0].slice(0, e);
                            i[2] = dj.slice(0, e)
                        }
                    }
                    return i.slice(0, 3)
                }
            },
            filter: {
                TAG: function(i) {
                    var e = i.replace(cp, c1).toLowerCase();
                    return i === "*" ?
                    function() {
                        return true
                    }: function(dj) {
                        return dj.nodeName && dj.nodeName.toLowerCase() === e
                    }
                },
                CLASS: function(e) {
                    var i = b6[e + " "];
                    return i || (i = new RegExp("(^|" + cm + ")" + e + "(" + cm + "|$)")) && b6(e,
                    function(dj) {
                        return i.test(typeof dj.className === "string" && dj.className || typeof dj.getAttribute !== da && dj.getAttribute("class") || "")
                    })
                },
                ATTR: function(dj, i, e) {
                    return function(dl) {
                        var dk = cs.attr(dl, dj);
                        if (dk == null) {
                            return i === "!="
                        }
                        if (!i) {
                            return true
                        }
                        dk += "";
                        return i === "=" ? dk === e: i === "!=" ? dk !== e: i === "^=" ? e && dk.indexOf(e) === 0 : i === "*=" ? e && dk.indexOf(e) > -1 : i === "$=" ? e && dk.slice( - e.length) === e: i === "~=" ? (" " + dk + " ").indexOf(e) > -1 : i === "|=" ? dk === e || dk.slice(0, e.length + 1) === e + "-": false
                    }
                },
                CHILD: function(i, dl, dk, dm, dj) {
                    var dp = i.slice(0, 3) !== "nth",
                    e = i.slice( - 4) !== "last",
                    dn = dl === "of-type";
                    return dm === 1 && dj === 0 ?
                    function(dq) {
                        return !! dq.parentNode
                    }: function(dw, du, dz) {
                        var dq, dC, dx, dB, dy, dt, dv = dp !== e ? "nextSibling": "previousSibling",
                        dA = dw.parentNode,
                        ds = dn && dw.nodeName.toLowerCase(),
                        dr = !dz && !dn;
                        if (dA) {
                            if (dp) {
                                while (dv) {
                                    dx = dw;
                                    while ((dx = dx[dv])) {
                                        if (dn ? dx.nodeName.toLowerCase() === ds: dx.nodeType === 1) {
                                            return false
                                        }
                                    }
                                    dt = dv = i === "only" && !dt && "nextSibling"
                                }
                                return true
                            }
                            dt = [e ? dA.firstChild: dA.lastChild];
                            if (e && dr) {
                                dC = dA[c6] || (dA[c6] = {});
                                dq = dC[i] || [];
                                dy = dq[0] === df && dq[1];
                                dB = dq[0] === df && dq[2];
                                dx = dy && dA.childNodes[dy];
                                while ((dx = ++dy && dx && dx[dv] || (dB = dy = 0) || dt.pop())) {
                                    if (dx.nodeType === 1 && ++dB && dx === dw) {
                                        dC[i] = [df, dy, dB];
                                        break
                                    }
                                }
                            } else {
                                if (dr && (dq = (dw[c6] || (dw[c6] = {}))[i]) && dq[0] === df) {
                                    dB = dq[1]
                                } else {
                                    while ((dx = ++dy && dx && dx[dv] || (dB = dy = 0) || dt.pop())) {
                                        if ((dn ? dx.nodeName.toLowerCase() === ds: dx.nodeType === 1) && ++dB) {
                                            if (dr) { (dx[c6] || (dx[c6] = {}))[i] = [df, dB]
                                            }
                                            if (dx === dw) {
                                                break
                                            }
                                        }
                                    }
                                }
                            }
                            dB -= dj;
                            return dB === dm || (dB % dm === 0 && dB / dm >= 0)
                        }
                    }
                },
                PSEUDO: function(dk, dj) {
                    var e, i = ck.pseudos[dk] || ck.setFilters[dk.toLowerCase()] || cs.error("unsupported pseudo: " + dk);
                    if (i[c6]) {
                        return i(dj)
                    }
                    if (i.length > 1) {
                        e = [dk, dk, "", dj];
                        return ck.setFilters.hasOwnProperty(dk.toLowerCase()) ? cg(function(dn, dq) {
                            var dm, dl = i(dn, dj),
                            dp = dl.length;
                            while (dp--) {
                                dm = ca.call(dn, dl[dp]);
                                dn[dm] = !(dq[dm] = dl[dp])
                            }
                        }) : function(dl) {
                            return i(dl, 0, e)
                        }
                    }
                    return i
                }
            },
            pseudos: {
                not: cg(function(e) {
                    var i = [],
                    dj = [],
                    dk = cS(e.replace(co, "$1"));
                    return dk[c6] ? cg(function(dm, ds, dq, dn) {
                        var dr, dl = dk(dm, null, dn, []),
                        dp = dm.length;
                        while (dp--) {
                            if ((dr = dl[dp])) {
                                dm[dp] = !(ds[dp] = dr)
                            }
                        }
                    }) : function(dn, dm, dl) {
                        i[0] = dn;
                        dk(i, null, dl, dj);
                        return ! dj.pop()
                    }
                }),
                has: cg(function(e) {
                    return function(i) {
                        return cs(e, i).length > 0
                    }
                }),
                contains: cg(function(e) {
                    return function(i) {
                        return (i.textContent || i.innerText || cD(i)).indexOf(e) > -1
                    }
                }),
                lang: cg(function(e) {
                    if (!cQ.test(e || "")) {
                        cs.error("unsupported lang: " + e)
                    }
                    e = e.replace(cp, c1).toLowerCase();
                    return function(dj) {
                        var i;
                        do {
                            if ((i = c4 ? dj.lang: dj.getAttribute("xml:lang") || dj.getAttribute("lang"))) {
                                i = i.toLowerCase();
                                return i === e || i.indexOf(e + "-") === 0
                            }
                        } while (( dj = dj . parentNode ) && dj.nodeType === 1);
                        return false
                    }
                }),
                target: function(e) {
                    var i = db.location && db.location.hash;
                    return i && i.slice(1) === e.id
                },
                root: function(e) {
                    return e === cl
                },
                focus: function(e) {
                    return e === cy.activeElement && (!cy.hasFocus || cy.hasFocus()) && !!(e.type || e.href || ~e.tabIndex)
                },
                enabled: function(e) {
                    return e.disabled === false
                },
                disabled: function(e) {
                    return e.disabled === true
                },
                checked: function(e) {
                    var i = e.nodeName.toLowerCase();
                    return (i === "input" && !!e.checked) || (i === "option" && !!e.selected)
                },
                selected: function(e) {
                    if (e.parentNode) {
                        e.parentNode.selectedIndex
                    }
                    return e.selected === true
                },
                empty: function(e) {
                    for (e = e.firstChild; e; e = e.nextSibling) {
                        if (e.nodeType < 6) {
                            return false
                        }
                    }
                    return true
                },
                parent: function(e) {
                    return ! ck.pseudos.empty(e)
                },
                header: function(e) {
                    return ci.test(e.nodeName)
                },
                input: function(e) {
                    return b9.test(e.nodeName)
                },
                button: function(i) {
                    var e = i.nodeName.toLowerCase();
                    return e === "input" && i.type === "button" || e === "button"
                },
                text: function(i) {
                    var e;
                    return i.nodeName.toLowerCase() === "input" && i.type === "text" && ((e = i.getAttribute("type")) == null || e.toLowerCase() === "text")
                },
                first: c3(function() {
                    return [0]
                }),
                last: c3(function(e, i) {
                    return [i - 1]
                }),
                eq: c3(function(e, dj, i) {
                    return [i < 0 ? i + dj: i]
                }),
                even: c3(function(e, dk) {
                    var dj = 0;
                    for (; dj < dk; dj += 2) {
                        e.push(dj)
                    }
                    return e
                }),
                odd: c3(function(e, dk) {
                    var dj = 1;
                    for (; dj < dk; dj += 2) {
                        e.push(dj)
                    }
                    return e
                }),
                lt: c3(function(e, dl, dk) {
                    var dj = dk < 0 ? dk + dl: dk;
                    for (; --dj >= 0;) {
                        e.push(dj)
                    }
                    return e
                }),
                gt: c3(function(e, dl, dk) {
                    var dj = dk < 0 ? dk + dl: dk;
                    for (; ++dj < dl;) {
                        e.push(dj)
                    }
                    return e
                })
            }
        };
        ck.pseudos.nth = ck.pseudos.eq;
        for (cu in {
            radio: true,
            checkbox: true,
            file: true,
            password: true,
            image: true
        }) {
            ck.pseudos[cu] = ct(cu)
        }
        for (cu in {
            submit: true,
            reset: true
        }) {
            ck.pseudos[cu] = b8(cu)
        }
        function cR() {}
        cR.prototype = ck.filters = ck.pseudos;
        ck.setFilters = new cR();
        ce = cs.tokenize = function(dl, dr) {
            var i, dm, dp, dq, dn, dj, e, dk = c5[dl + " "];
            if (dk) {
                return dr ? 0 : dk.slice(0)
            }
            dn = dl;
            dj = [];
            e = ck.preFilter;
            while (dn) {
                if (!i || (dm = cr.exec(dn))) {
                    if (dm) {
                        dn = dn.slice(dm[0].length) || dn
                    }
                    dj.push((dp = []))
                }
                i = false;
                if ((dm = cx.exec(dn))) {
                    i = dm.shift();
                    dp.push({
                        value: i,
                        type: dm[0].replace(co, " ")
                    });
                    dn = dn.slice(i.length)
                }
                for (dq in ck.filter) {
                    if ((dm = cY[dq].exec(dn)) && (!e[dq] || (dm = e[dq](dm)))) {
                        i = dm.shift();
                        dp.push({
                            value: i,
                            type: dq,
                            matches: dm
                        });
                        dn = dn.slice(i.length)
                    }
                }
                if (!i) {
                    break
                }
            }
            return dr ? dn.length: dn ? cs.error(dl) : c5(dl, dj).slice(0)
        };
        function cf(dl) {
            var dk = 0,
            dj = dl.length,
            e = "";
            for (; dk < dj; dk++) {
                e += dl[dk].value
            }
            return e
        }
        function cn(dl, dj, dk) {
            var e = dj.dir,
            dm = dk && e === "parentNode",
            i = c0++;
            return dj.first ?
            function(dq, dp, dn) {
                while ((dq = dq[e])) {
                    if (dq.nodeType === 1 || dm) {
                        return dl(dq, dp, dn)
                    }
                }
            }: function(ds, dq, dp) {
                var dt, dr, dn = [df, i];
                if (dp) {
                    while ((ds = ds[e])) {
                        if (ds.nodeType === 1 || dm) {
                            if (dl(ds, dq, dp)) {
                                return true
                            }
                        }
                    }
                } else {
                    while ((ds = ds[e])) {
                        if (ds.nodeType === 1 || dm) {
                            dr = ds[c6] || (ds[c6] = {});
                            if ((dt = dr[e]) && dt[0] === df && dt[1] === i) {
                                return (dn[2] = dt[2])
                            } else {
                                dr[e] = dn;
                                if ((dn[2] = dl(ds, dq, dp))) {
                                    return true
                                }
                            }
                        }
                    }
                }
            }
        }
        function dh(e) {
            return e.length > 1 ?
            function(dm, dl, dj) {
                var dk = e.length;
                while (dk--) {
                    if (!e[dk](dm, dl, dj)) {
                        return false
                    }
                }
                return true
            }: e[0]
        }
        function cv(dj, dm, dl) {
            var dk = 0,
            e = dm.length;
            for (; dk < e; dk++) {
                cs(dj, dm[dk], dl)
            }
            return dl
        }
        function cW(e, dj, dk, dl, dp) {
            var dm, ds = [],
            dn = 0,
            dq = e.length,
            dr = dj != null;
            for (; dn < dq; dn++) {
                if ((dm = e[dn])) {
                    if (!dk || dk(dm, dl, dp)) {
                        ds.push(dm);
                        if (dr) {
                            dj.push(dn)
                        }
                    }
                }
            }
            return ds
        }
        function cd(dj, i, dl, dk, dm, e) {
            if (dk && !dk[c6]) {
                dk = cd(dk)
            }
            if (dm && !dm[c6]) {
                dm = cd(dm, e)
            }
            return cg(function(dy, dv, dq, dx) {
                var dA, dw, ds, dr = [],
                dz = [],
                dp = dv.length,
                dn = dy || cv(i || "*", dq.nodeType ? [dq] : dq, []),
                dt = dj && (dy || !i) ? cW(dn, dr, dj, dq, dx) : dn,
                du = dl ? dm || (dy ? dj: dp || dk) ? [] : dv: dt;
                if (dl) {
                    dl(dt, du, dq, dx)
                }
                if (dk) {
                    dA = cW(du, dz);
                    dk(dA, [], dq, dx);
                    dw = dA.length;
                    while (dw--) {
                        if ((ds = dA[dw])) {
                            du[dz[dw]] = !(dt[dz[dw]] = ds)
                        }
                    }
                }
                if (dy) {
                    if (dm || dj) {
                        if (dm) {
                            dA = [];
                            dw = du.length;
                            while (dw--) {
                                if ((ds = du[dw])) {
                                    dA.push((dt[dw] = ds))
                                }
                            }
                            dm(null, (du = []), dA, dx)
                        }
                        dw = du.length;
                        while (dw--) {
                            if ((ds = du[dw]) && (dA = dm ? ca.call(dy, ds) : dr[dw]) > -1) {
                                dy[dA] = !(dv[dA] = ds)
                            }
                        }
                    }
                } else {
                    du = cW(du === dv ? du.splice(dp, du.length) : du);
                    if (dm) {
                        dm(null, dv, du, dx)
                    } else {
                        b4.apply(dv, du)
                    }
                }
            })
        }
        function c7(dp) {
            var dj, dm, dk, dn = dp.length,
            ds = ck.relative[dp[0].type],
            dt = ds || ck.relative[" "],
            dl = ds ? 1 : 0,
            dq = cn(function(i) {
                return i === dj
            },
            dt, true),
            dr = cn(function(i) {
                return ca.call(dj, i) > -1
            },
            dt, true),
            e = [function(dv, du, i) {
                return (!ds && (i || du !== di)) || ((dj = du).nodeType ? dq(dv, du, i) : dr(dv, du, i))
            }];
            for (; dl < dn; dl++) {
                if ((dm = ck.relative[dp[dl].type])) {
                    e = [cn(dh(e), dm)]
                } else {
                    dm = ck.filter[dp[dl].type].apply(null, dp[dl].matches);
                    if (dm[c6]) {
                        dk = ++dl;
                        for (; dk < dn; dk++) {
                            if (ck.relative[dp[dk].type]) {
                                break
                            }
                        }
                        return cd(dl > 1 && dh(e), dl > 1 && cf(dp.slice(0, dl - 1).concat({
                            value: dp[dl - 2].type === " " ? "*": ""
                        })).replace(co, "$1"), dm, dl < dk && c7(dp.slice(dl, dk)), dk < dn && c7((dp = dp.slice(dk))), dk < dn && cf(dp))
                    }
                    e.push(dm)
                }
            }
            return dh(e)
        }
        function cU(dk, dj) {
            var e = dj.length > 0,
            dl = dk.length > 0,
            i = function(dw, dq, dv, du, dz) {
                var dr, ds, dx, dB = 0,
                dt = "0",
                dm = dw && [],
                dC = [],
                dA = di,
                dp = dw || dl && ck.find.TAG("*", dz),
                dn = (df += dA == null ? 1 : Math.random() || 0.1),
                dy = dp.length;
                if (dz) {
                    di = dq !== cy && dq
                }
                for (; dt !== dy && (dr = dp[dt]) != null; dt++) {
                    if (dl && dr) {
                        ds = 0;
                        while ((dx = dk[ds++])) {
                            if (dx(dr, dq, dv)) {
                                du.push(dr);
                                break
                            }
                        }
                        if (dz) {
                            df = dn
                        }
                    }
                    if (e) {
                        if ((dr = !dx && dr)) {
                            dB--
                        }
                        if (dw) {
                            dm.push(dr)
                        }
                    }
                }
                dB += dt;
                if (e && dt !== dB) {
                    ds = 0;
                    while ((dx = dj[ds++])) {
                        dx(dm, dC, dq, dv)
                    }
                    if (dw) {
                        if (dB > 0) {
                            while (dt--) {
                                if (! (dm[dt] || dC[dt])) {
                                    dC[dt] = c9.call(du)
                                }
                            }
                        }
                        dC = cW(dC)
                    }
                    b4.apply(du, dC);
                    if (dz && !dw && dC.length > 0 && (dB + dj.length) > 1) {
                        cs.uniqueSort(du)
                    }
                }
                if (dz) {
                    df = dn;
                    di = dA
                }
                return dm
            };
            return e ? cg(i) : i
        }
        cS = cs.compile = function(e, dk) {
            var dl, dj = [],
            dn = [],
            dm = cC[e + " "];
            if (!dm) {
                if (!dk) {
                    dk = ce(e)
                }
                dl = dk.length;
                while (dl--) {
                    dm = c7(dk[dl]);
                    if (dm[c6]) {
                        dj.push(dm)
                    } else {
                        dn.push(dm)
                    }
                }
                dm = cC(e, cU(dn, dj));
                dm.selector = e
            }
            return dm
        };
        dd = cs.select = function(dk, e, dl, dp) {
            var dm, ds, dj, dt, dq, dr = typeof dk === "function" && dk,
            dn = !dp && ce((dk = dr.selector || dk));
            dl = dl || [];
            if (dn.length === 1) {
                ds = dn[0] = dn[0].slice(0);
                if (ds.length > 2 && (dj = ds[0]).type === "ID" && de.getById && e.nodeType === 9 && c4 && ck.relative[ds[1].type]) {
                    e = (ck.find.ID(dj.matches[0].replace(cp, c1), e) || [])[0];
                    if (!e) {
                        return dl
                    } else {
                        if (dr) {
                            e = e.parentNode
                        }
                    }
                    dk = dk.slice(ds.shift().value.length)
                }
                dm = cY.needsContext.test(dk) ? 0 : ds.length;
                while (dm--) {
                    dj = ds[dm];
                    if (ck.relative[(dt = dj.type)]) {
                        break
                    }
                    if ((dq = ck.find[dt])) {
                        if ((dp = dq(dj.matches[0].replace(cp, c1), cX.test(ds[0].type) && cP(e.parentNode) || e))) {
                            ds.splice(dm, 1);
                            dk = dp.length && cf(ds);
                            if (!dk) {
                                b4.apply(dl, dp);
                                return dl
                            }
                            break
                        }
                    }
                }
            } (dr || cS(dk, dn))(dp, e, !c4, dl, cX.test(dk) && cP(e.parentNode) || e);
            return dl
        };
        de.sortStable = c6.split("").sort(cA).join("") === c6;
        de.detectDuplicates = !!cT;
        cV();
        de.sortDetached = cc(function(e) {
            return e.compareDocumentPosition(cy.createElement("div")) & 1
        });
        if (!cc(function(e) {
            e.innerHTML = "<a href='#'></a>";
            return e.firstChild.getAttribute("href") === "#"
        })) {
            dg("type|href|height|width",
            function(i, e, dj) {
                if (!dj) {
                    return i.getAttribute(e, e.toLowerCase() === "type" ? 1 : 2)
                }
            })
        }
        if (!de.attributes || !cc(function(e) {
            e.innerHTML = "<input/>";
            e.firstChild.setAttribute("value", "");
            return e.firstChild.getAttribute("value") === ""
        })) {
            dg("value",
            function(i, e, dj) {
                if (!dj && i.nodeName.toLowerCase() === "input") {
                    return i.defaultValue
                }
            })
        }
        if (!cc(function(e) {
            return e.getAttribute("disabled") == null
        })) {
            dg(b5,
            function(i, e, dk) {
                var dj;
                if (!dk) {
                    return i[e] === true ? e.toLowerCase() : (dj = i.getAttributeNode(e)) && dj.specified ? dj.value: null
                }
            })
        }
        return cs
    })(a3);
    bF.find = m;
    bF.expr = m.selectors;
    bF.expr[":"] = bF.expr.pseudos;
    bF.unique = m.uniqueSort;
    bF.text = m.getText;
    bF.isXMLDoc = m.isXML;
    bF.contains = m.contains;
    var z = bF.expr.match.needsContext;
    var a = (/^<(\w+)\s*\/?>(?:<\/\1>|)$/);
    var aJ = /^.[^:#\[\.,]*$/;
    function aP(b3, e, i) {
        if (bF.isFunction(e)) {
            return bF.grep(b3,
            function(b5, b4) {
                return !! e.call(b5, b4, b5) !== i
            })
        }
        if (e.nodeType) {
            return bF.grep(b3,
            function(b4) {
                return (b4 === e) !== i
            })
        }
        if (typeof e === "string") {
            if (aJ.test(e)) {
                return bF.filter(e, b3, i)
            }
            e = bF.filter(e, b3)
        }
        return bF.grep(b3,
        function(b4) {
            return (bF.inArray(b4, e) >= 0) !== i
        })
    }
    bF.filter = function(b4, e, b3) {
        var i = e[0];
        if (b3) {
            b4 = ":not(" + b4 + ")"
        }
        return e.length === 1 && i.nodeType === 1 ? bF.find.matchesSelector(i, b4) ? [i] : [] : bF.find.matches(b4, bF.grep(e,
        function(b5) {
            return b5.nodeType === 1
        }))
    };
    bF.fn.extend({
        find: function(b3) {
            var b6, b5 = [],
            b4 = this,
            e = b4.length;
            if (typeof b3 !== "string") {
                return this.pushStack(bF(b3).filter(function() {
                    for (b6 = 0; b6 < e; b6++) {
                        if (bF.contains(b4[b6], this)) {
                            return true
                        }
                    }
                }))
            }
            for (b6 = 0; b6 < e; b6++) {
                bF.find(b3, b4[b6], b5)
            }
            b5 = this.pushStack(e > 1 ? bF.unique(b5) : b5);
            b5.selector = this.selector ? this.selector + " " + b3: b3;
            return b5
        },
        filter: function(e) {
            return this.pushStack(aP(this, e || [], false))
        },
        not: function(e) {
            return this.pushStack(aP(this, e || [], true))
        },
        is: function(e) {
            return !! aP(this, typeof e === "string" && z.test(e) ? bF(e) : e || [], false).length
        }
    });
    var y, n = a3.document,
    bq = /^(?:\s*(<[\w\W]+>)[^>]*|#([\w-]*))$/,
    bS = bF.fn.init = function(e, b3) {
        var i, b4;
        if (!e) {
            return this
        }
        if (typeof e === "string") {
            if (e.charAt(0) === "<" && e.charAt(e.length - 1) === ">" && e.length >= 3) {
                i = [null, e, null]
            } else {
                i = bq.exec(e)
            }
            if (i && (i[1] || !b3)) {
                if (i[1]) {
                    b3 = b3 instanceof bF ? b3[0] : b3;
                    bF.merge(this, bF.parseHTML(i[1], b3 && b3.nodeType ? b3.ownerDocument || b3: n, true));
                    if (a.test(i[1]) && bF.isPlainObject(b3)) {
                        for (i in b3) {
                            if (bF.isFunction(this[i])) {
                                this[i](b3[i])
                            } else {
                                this.attr(i, b3[i])
                            }
                        }
                    }
                    return this
                } else {
                    b4 = n.getElementById(i[2]);
                    if (b4 && b4.parentNode) {
                        if (b4.id !== i[2]) {
                            return y.find(e)
                        }
                        this.length = 1;
                        this[0] = b4
                    }
                    this.context = n;
                    this.selector = e;
                    return this
                }
            } else {
                if (!b3 || b3.jquery) {
                    return (b3 || y).find(e)
                } else {
                    return this.constructor(b3).find(e)
                }
            }
        } else {
            if (e.nodeType) {
                this.context = this[0] = e;
                this.length = 1;
                return this
            } else {
                if (bF.isFunction(e)) {
                    return typeof y.ready !== "undefined" ? y.ready(e) : e(bF)
                }
            }
        }
        if (e.selector !== undefined) {
            this.selector = e.selector;
            this.context = e.context
        }
        return bF.makeArray(e, this)
    };
    bS.prototype = bF.fn;
    y = bF(n);
    var bs = /^(?:parents|prev(?:Until|All))/,
    bw = {
        children: true,
        contents: true,
        next: true,
        prev: true
    };
    bF.extend({
        dir: function(b3, i, b5) {
            var e = [],
            b4 = b3[i];
            while (b4 && b4.nodeType !== 9 && (b5 === undefined || b4.nodeType !== 1 || !bF(b4).is(b5))) {
                if (b4.nodeType === 1) {
                    e.push(b4)
                }
                b4 = b4[i]
            }
            return e
        },
        sibling: function(b3, i) {
            var e = [];
            for (; b3; b3 = b3.nextSibling) {
                if (b3.nodeType === 1 && b3 !== i) {
                    e.push(b3)
                }
            }
            return e
        }
    });
    bF.fn.extend({
        has: function(b5) {
            var b4, b3 = bF(b5, this),
            e = b3.length;
            return this.filter(function() {
                for (b4 = 0; b4 < e; b4++) {
                    if (bF.contains(this, b3[b4])) {
                        return true
                    }
                }
            })
        },
        closest: function(b6, b5) {
            var b7, b4 = 0,
            b3 = this.length,
            e = [],
            b8 = z.test(b6) || typeof b6 !== "string" ? bF(b6, b5 || this.context) : 0;
            for (; b4 < b3; b4++) {
                for (b7 = this[b4]; b7 && b7 !== b5; b7 = b7.parentNode) {
                    if (b7.nodeType < 11 && (b8 ? b8.index(b7) > -1 : b7.nodeType === 1 && bF.find.matchesSelector(b7, b6))) {
                        e.push(b7);
                        break
                    }
                }
            }
            return this.pushStack(e.length > 1 ? bF.unique(e) : e)
        },
        index: function(e) {
            if (!e) {
                return (this[0] && this[0].parentNode) ? this.first().prevAll().length: -1
            }
            if (typeof e === "string") {
                return bF.inArray(this[0], bF(e))
            }
            return bF.inArray(e.jquery ? e[0] : e, this)
        },
        add: function(e, i) {
            return this.pushStack(bF.unique(bF.merge(this.get(), bF(e, i))))
        },
        addBack: function(e) {
            return this.add(e == null ? this.prevObject: this.prevObject.filter(e))
        }
    });
    function aW(i, e) {
        do {
            i = i[e]
        } while ( i && i . nodeType !== 1 );
        return i
    }
    bF.each({
        parent: function(i) {
            var e = i.parentNode;
            return e && e.nodeType !== 11 ? e: null
        },
        parents: function(e) {
            return bF.dir(e, "parentNode")
        },
        parentsUntil: function(b3, e, b4) {
            return bF.dir(b3, "parentNode", b4)
        },
        next: function(e) {
            return aW(e, "nextSibling")
        },
        prev: function(e) {
            return aW(e, "previousSibling")
        },
        nextAll: function(e) {
            return bF.dir(e, "nextSibling")
        },
        prevAll: function(e) {
            return bF.dir(e, "previousSibling")
        },
        nextUntil: function(b3, e, b4) {
            return bF.dir(b3, "nextSibling", b4)
        },
        prevUntil: function(b3, e, b4) {
            return bF.dir(b3, "previousSibling", b4)
        },
        siblings: function(e) {
            return bF.sibling((e.parentNode || {}).firstChild, e)
        },
        children: function(e) {
            return bF.sibling(e.firstChild)
        },
        contents: function(e) {
            return bF.nodeName(e, "iframe") ? e.contentDocument || e.contentWindow.document: bF.merge([], e.childNodes)
        }
    },
    function(e, i) {
        bF.fn[e] = function(b5, b3) {
            var b4 = bF.map(this, i, b5);
            if (e.slice( - 5) !== "Until") {
                b3 = b5
            }
            if (b3 && typeof b3 === "string") {
                b4 = bF.filter(b3, b4)
            }
            if (this.length > 1) {
                if (!bw[e]) {
                    b4 = bF.unique(b4)
                }
                if (bs.test(e)) {
                    b4 = b4.reverse()
                }
            }
            return this.pushStack(b4)
        }
    });
    var aD = (/\S+/g);
    var bZ = {};
    function ad(i) {
        var e = bZ[i] = {};
        bF.each(i.match(aD) || [],
        function(b4, b3) {
            e[b3] = true
        });
        return e
    }
    bF.Callbacks = function(cb) {
        cb = typeof cb === "string" ? (bZ[cb] || ad(cb)) : bF.extend({},
        cb);
        var b5, b4, e, b6, b7, b3, b8 = [],
        b9 = !cb.once && [],
        i = function(cc) {
            b4 = cb.memory && cc;
            e = true;
            b7 = b3 || 0;
            b3 = 0;
            b6 = b8.length;
            b5 = true;
            for (; b8 && b7 < b6; b7++) {
                if (b8[b7].apply(cc[0], cc[1]) === false && cb.stopOnFalse) {
                    b4 = false;
                    break
                }
            }
            b5 = false;
            if (b8) {
                if (b9) {
                    if (b9.length) {
                        i(b9.shift())
                    }
                } else {
                    if (b4) {
                        b8 = []
                    } else {
                        ca.disable()
                    }
                }
            }
        },
        ca = {
            add: function() {
                if (b8) {
                    var cd = b8.length; (function cc(ce) {
                        bF.each(ce,
                        function(cg, cf) {
                            var ch = bF.type(cf);
                            if (ch === "function") {
                                if (!cb.unique || !ca.has(cf)) {
                                    b8.push(cf)
                                }
                            } else {
                                if (cf && cf.length && ch !== "string") {
                                    cc(cf)
                                }
                            }
                        })
                    })(arguments);
                    if (b5) {
                        b6 = b8.length
                    } else {
                        if (b4) {
                            b3 = cd;
                            i(b4)
                        }
                    }
                }
                return this
            },
            remove: function() {
                if (b8) {
                    bF.each(arguments,
                    function(ce, cc) {
                        var cd;
                        while ((cd = bF.inArray(cc, b8, cd)) > -1) {
                            b8.splice(cd, 1);
                            if (b5) {
                                if (cd <= b6) {
                                    b6--
                                }
                                if (cd <= b7) {
                                    b7--
                                }
                            }
                        }
                    })
                }
                return this
            },
            has: function(cc) {
                return cc ? bF.inArray(cc, b8) > -1 : !!(b8 && b8.length)
            },
            empty: function() {
                b8 = [];
                b6 = 0;
                return this
            },
            disable: function() {
                b8 = b9 = b4 = undefined;
                return this
            },
            disabled: function() {
                return ! b8
            },
            lock: function() {
                b9 = undefined;
                if (!b4) {
                    ca.disable()
                }
                return this
            },
            locked: function() {
                return ! b9
            },
            fireWith: function(cd, cc) {
                if (b8 && (!e || b9)) {
                    cc = cc || [];
                    cc = [cd, cc.slice ? cc.slice() : cc];
                    if (b5) {
                        b9.push(cc)
                    } else {
                        i(cc)
                    }
                }
                return this
            },
            fire: function() {
                ca.fireWith(this, arguments);
                return this
            },
            fired: function() {
                return !! e
            }
        };
        return ca
    };
    bF.extend({
        Deferred: function(b3) {
            var i = [["resolve", "done", bF.Callbacks("once memory"), "resolved"], ["reject", "fail", bF.Callbacks("once memory"), "rejected"], ["notify", "progress", bF.Callbacks("memory")]],
            b4 = "pending",
            b5 = {
                state: function() {
                    return b4
                },
                always: function() {
                    e.done(arguments).fail(arguments);
                    return this
                },
                then: function() {
                    var b6 = arguments;
                    return bF.Deferred(function(b7) {
                        bF.each(i,
                        function(b9, b8) {
                            var ca = bF.isFunction(b6[b9]) && b6[b9];
                            e[b8[1]](function() {
                                var cb = ca && ca.apply(this, arguments);
                                if (cb && bF.isFunction(cb.promise)) {
                                    cb.promise().done(b7.resolve).fail(b7.reject).progress(b7.notify)
                                } else {
                                    b7[b8[0] + "With"](this === b5 ? b7.promise() : this, ca ? [cb] : arguments)
                                }
                            })
                        });
                        b6 = null
                    }).promise()
                },
                promise: function(b6) {
                    return b6 != null ? bF.extend(b6, b5) : b5
                }
            },
            e = {};
            b5.pipe = b5.then;
            bF.each(i,
            function(b7, b6) {
                var b9 = b6[2],
                b8 = b6[3];
                b5[b6[1]] = b9.add;
                if (b8) {
                    b9.add(function() {
                        b4 = b8
                    },
                    i[b7 ^ 1][2].disable, i[2][2].lock)
                }
                e[b6[0]] = function() {
                    e[b6[0] + "With"](this === e ? b5: this, arguments);
                    return this
                };
                e[b6[0] + "With"] = b9.fireWith
            });
            b5.promise(e);
            if (b3) {
                b3.call(e, e)
            }
            return e
        },
        when: function(b6) {
            var b4 = 0,
            b8 = N.call(arguments),
            e = b8.length,
            b3 = e !== 1 || (b6 && bF.isFunction(b6.promise)) ? e: 0,
            cb = b3 === 1 ? b6: bF.Deferred(),
            b5 = function(cd, ce, cc) {
                return function(i) {
                    ce[cd] = this;
                    cc[cd] = arguments.length > 1 ? N.call(arguments) : i;
                    if (cc === ca) {
                        cb.notifyWith(ce, cc)
                    } else {
                        if (! (--b3)) {
                            cb.resolveWith(ce, cc)
                        }
                    }
                }
            },
            ca,
            b7,
            b9;
            if (e > 1) {
                ca = new Array(e);
                b7 = new Array(e);
                b9 = new Array(e);
                for (; b4 < e; b4++) {
                    if (b8[b4] && bF.isFunction(b8[b4].promise)) {
                        b8[b4].promise().done(b5(b4, b9, b8)).fail(cb.reject).progress(b5(b4, b7, ca))
                    } else {--b3
                    }
                }
            }
            if (!b3) {
                cb.resolveWith(b9, b8)
            }
            return cb.promise()
        }
    });
    var ai;
    bF.fn.ready = function(e) {
        bF.ready.promise().done(e);
        return this
    };
    bF.extend({
        isReady: false,
        readyWait: 1,
        holdReady: function(e) {
            if (e) {
                bF.readyWait++
            } else {
                bF.ready(true)
            }
        },
        ready: function(e) {
            if (e === true ? --bF.readyWait: bF.isReady) {
                return
            }
            if (!n.body) {
                return setTimeout(bF.ready)
            }
            bF.isReady = true;
            if (e !== true && --bF.readyWait > 0) {
                return
            }
            ai.resolveWith(n, [bF]);
            if (bF.fn.triggerHandler) {
                bF(n).triggerHandler("ready");
                bF(n).off("ready")
            }
        }
    });
    function bj() {
        if (n.addEventListener) {
            n.removeEventListener("DOMContentLoaded", bW, false);
            a3.removeEventListener("load", bW, false)
        } else {
            n.detachEvent("onreadystatechange", bW);
            a3.detachEvent("onload", bW)
        }
    }
    function bW() {
        if (n.addEventListener || event.type === "load" || n.readyState === "complete") {
            bj();
            bF.ready()
        }
    }
    bF.ready.promise = function(b5) {
        if (!ai) {
            ai = bF.Deferred();
            if (n.readyState === "complete") {
                setTimeout(bF.ready)
            } else {
                if (n.addEventListener) {
                    n.addEventListener("DOMContentLoaded", bW, false);
                    a3.addEventListener("load", bW, false)
                } else {
                    n.attachEvent("onreadystatechange", bW);
                    a3.attachEvent("onload", bW);
                    var b4 = false;
                    try {
                        b4 = a3.frameElement == null && n.documentElement
                    } catch(b3) {}
                    if (b4 && b4.doScroll) { (function i() {
                            if (!bF.isReady) {
                                try {
                                    b4.doScroll("left")
                                } catch(b6) {
                                    return setTimeout(i, 50)
                                }
                                bj();
                                bF.ready()
                            }
                        })()
                    }
                }
            }
        }
        return ai.promise(b5)
    };
    var aA = typeof undefined;
    var bf;
    for (bf in bF(C)) {
        break
    }
    C.ownLast = bf !== "0";
    C.inlineBlockNeedsLayout = false;
    bF(function() {
        var b3, b4, e, i;
        e = n.getElementsByTagName("body")[0];
        if (!e || !e.style) {
            return
        }
        b4 = n.createElement("div");
        i = n.createElement("div");
        i.style.cssText = "position:absolute;border:0;width:0;height:0;top:0;left:-9999px";
        e.appendChild(i).appendChild(b4);
        if (typeof b4.style.zoom !== aA) {
            b4.style.cssText = "display:inline;margin:0;border:0;padding:1px;width:1px;zoom:1";
            C.inlineBlockNeedsLayout = b3 = b4.offsetWidth === 3;
            if (b3) {
                e.style.zoom = 1
            }
        }
        e.removeChild(i)
    }); (function() {
        var b3 = n.createElement("div");
        if (C.deleteExpando == null) {
            C.deleteExpando = true;
            try {
                delete b3.test
            } catch(i) {
                C.deleteExpando = false
            }
        }
        b3 = null
    })();
    bF.acceptData = function(b3) {
        var i = bF.noData[(b3.nodeName + " ").toLowerCase()],
        e = +b3.nodeType || 1;
        return e !== 1 && e !== 9 ? false: !i || i !== true && b3.getAttribute("classid") === i
    };
    var bv = /^(?:\{[\w\W]*\}|\[[\w\W]*\])$/,
    aO = /([A-Z])/g;
    function bx(b4, b3, b5) {
        if (b5 === undefined && b4.nodeType === 1) {
            var i = "data-" + b3.replace(aO, "-$1").toLowerCase();
            b5 = b4.getAttribute(i);
            if (typeof b5 === "string") {
                try {
                    b5 = b5 === "true" ? true: b5 === "false" ? false: b5 === "null" ? null: +b5 + "" === b5 ? +b5: bv.test(b5) ? bF.parseJSON(b5) : b5
                } catch(b6) {}
                bF.data(b4, b3, b5)
            } else {
                b5 = undefined
            }
        }
        return b5
    }
    function O(i) {
        var e;
        for (e in i) {
            if (e === "data" && bF.isEmptyObject(i[e])) {
                continue
            }
            if (e !== "toJSON") {
                return false
            }
        }
        return true
    }
    function ba(b4, i, b6, b5) {
        if (!bF.acceptData(b4)) {
            return
        }
        var b8, b7, b9 = bF.expando,
        ca = b4.nodeType,
        e = ca ? bF.cache: b4,
        b3 = ca ? b4[b9] : b4[b9] && b9;
        if ((!b3 || !e[b3] || (!b5 && !e[b3].data)) && b6 === undefined && typeof i === "string") {
            return
        }
        if (!b3) {
            if (ca) {
                b3 = b4[b9] = aN.pop() || bF.guid++
            } else {
                b3 = b9
            }
        }
        if (!e[b3]) {
            e[b3] = ca ? {}: {
                toJSON: bF.noop
            }
        }
        if (typeof i === "object" || typeof i === "function") {
            if (b5) {
                e[b3] = bF.extend(e[b3], i)
            } else {
                e[b3].data = bF.extend(e[b3].data, i)
            }
        }
        b7 = e[b3];
        if (!b5) {
            if (!b7.data) {
                b7.data = {}
            }
            b7 = b7.data
        }
        if (b6 !== undefined) {
            b7[bF.camelCase(i)] = b6
        }
        if (typeof i === "string") {
            b8 = b7[i];
            if (b8 == null) {
                b8 = b7[bF.camelCase(i)]
            }
        } else {
            b8 = b7
        }
        return b8
    }
    function Z(b6, b4, e) {
        if (!bF.acceptData(b6)) {
            return
        }
        var b8, b5, b7 = b6.nodeType,
        b3 = b7 ? bF.cache: b6,
        b9 = b7 ? b6[bF.expando] : bF.expando;
        if (!b3[b9]) {
            return
        }
        if (b4) {
            b8 = e ? b3[b9] : b3[b9].data;
            if (b8) {
                if (!bF.isArray(b4)) {
                    if (b4 in b8) {
                        b4 = [b4]
                    } else {
                        b4 = bF.camelCase(b4);
                        if (b4 in b8) {
                            b4 = [b4]
                        } else {
                            b4 = b4.split(" ")
                        }
                    }
                } else {
                    b4 = b4.concat(bF.map(b4, bF.camelCase))
                }
                b5 = b4.length;
                while (b5--) {
                    delete b8[b4[b5]]
                }
                if (e ? !O(b8) : !bF.isEmptyObject(b8)) {
                    return
                }
            }
        }
        if (!e) {
            delete b3[b9].data;
            if (!O(b3[b9])) {
                return
            }
        }
        if (b7) {
            bF.cleanData([b6], true)
        } else {
            if (C.deleteExpando || b3 != b3.window) {
                delete b3[b9]
            } else {
                b3[b9] = null
            }
        }
    }
    bF.extend({
        cache: {},
        noData: {
            "applet ": true,
            "embed ": true,
            "object ": "clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"
        },
        hasData: function(e) {
            e = e.nodeType ? bF.cache[e[bF.expando]] : e[bF.expando];
            return !! e && !O(e)
        },
        data: function(i, e, b3) {
            return ba(i, e, b3)
        },
        removeData: function(i, e) {
            return Z(i, e)
        },
        _data: function(i, e, b3) {
            return ba(i, e, b3, true)
        },
        _removeData: function(i, e) {
            return Z(i, e, true)
        }
    });
    bF.fn.extend({
        data: function(b5, b8) {
            var b4, b3, b7, b6 = this[0],
            e = b6 && b6.attributes;
            if (b5 === undefined) {
                if (this.length) {
                    b7 = bF.data(b6);
                    if (b6.nodeType === 1 && !bF._data(b6, "parsedAttrs")) {
                        b4 = e.length;
                        while (b4--) {
                            if (e[b4]) {
                                b3 = e[b4].name;
                                if (b3.indexOf("data-") === 0) {
                                    b3 = bF.camelCase(b3.slice(5));
                                    bx(b6, b3, b7[b3])
                                }
                            }
                        }
                        bF._data(b6, "parsedAttrs", true)
                    }
                }
                return b7
            }
            if (typeof b5 === "object") {
                return this.each(function() {
                    bF.data(this, b5)
                })
            }
            return arguments.length > 1 ? this.each(function() {
                bF.data(this, b5, b8)
            }) : b6 ? bx(b6, b5, bF.data(b6, b5)) : undefined
        },
        removeData: function(e) {
            return this.each(function() {
                bF.removeData(this, e)
            })
        }
    });
    bF.extend({
        queue: function(b3, i, b4) {
            var e;
            if (b3) {
                i = (i || "fx") + "queue";
                e = bF._data(b3, i);
                if (b4) {
                    if (!e || bF.isArray(b4)) {
                        e = bF._data(b3, i, bF.makeArray(b4))
                    } else {
                        e.push(b4)
                    }
                }
                return e || []
            }
        },
        dequeue: function(b6, b5) {
            b5 = b5 || "fx";
            var i = bF.queue(b6, b5),
            b7 = i.length,
            b4 = i.shift(),
            e = bF._queueHooks(b6, b5),
            b3 = function() {
                bF.dequeue(b6, b5)
            };
            if (b4 === "inprogress") {
                b4 = i.shift();
                b7--
            }
            if (b4) {
                if (b5 === "fx") {
                    i.unshift("inprogress")
                }
                delete e.stop;
                b4.call(b6, b3, e)
            }
            if (!b7 && e) {
                e.empty.fire()
            }
        },
        _queueHooks: function(b3, i) {
            var e = i + "queueHooks";
            return bF._data(b3, e) || bF._data(b3, e, {
                empty: bF.Callbacks("once memory").add(function() {
                    bF._removeData(b3, i + "queue");
                    bF._removeData(b3, e)
                })
            })
        }
    });
    bF.fn.extend({
        queue: function(e, i) {
            var b3 = 2;
            if (typeof e !== "string") {
                i = e;
                e = "fx";
                b3--
            }
            if (arguments.length < b3) {
                return bF.queue(this[0], e)
            }
            return i === undefined ? this: this.each(function() {
                var b4 = bF.queue(this, e, i);
                bF._queueHooks(this, e);
                if (e === "fx" && b4[0] !== "inprogress") {
                    bF.dequeue(this, e)
                }
            })
        },
        dequeue: function(e) {
            return this.each(function() {
                bF.dequeue(this, e)
            })
        },
        clearQueue: function(e) {
            return this.queue(e || "fx", [])
        },
        promise: function(b4, b8) {
            var b3, b5 = 1,
            b9 = bF.Deferred(),
            b7 = this,
            e = this.length,
            b6 = function() {
                if (! (--b5)) {
                    b9.resolveWith(b7, [b7])
                }
            };
            if (typeof b4 !== "string") {
                b8 = b4;
                b4 = undefined
            }
            b4 = b4 || "fx";
            while (e--) {
                b3 = bF._data(b7[e], b4 + "queueHooks");
                if (b3 && b3.empty) {
                    b5++;
                    b3.empty.add(b6)
                }
            }
            b6();
            return b9.promise(b8)
        }
    });
    var aC = (/[+-]?(?:\d*\.|)\d+(?:[eE][+-]?\d+|)/).source;
    var bQ = ["Top", "Right", "Bottom", "Left"];
    var Q = function(i, e) {
        i = e || i;
        return bF.css(i, "display") === "none" || !bF.contains(i.ownerDocument, i)
    };
    var az = bF.access = function(e, b7, b9, b8, b5, cb, ca) {
        var b4 = 0,
        b3 = e.length,
        b6 = b9 == null;
        if (bF.type(b9) === "object") {
            b5 = true;
            for (b4 in b9) {
                bF.access(e, b7, b4, b9[b4], true, cb, ca)
            }
        } else {
            if (b8 !== undefined) {
                b5 = true;
                if (!bF.isFunction(b8)) {
                    ca = true
                }
                if (b6) {
                    if (ca) {
                        b7.call(e, b8);
                        b7 = null
                    } else {
                        b6 = b7;
                        b7 = function(cc, i, cd) {
                            return b6.call(bF(cc), cd)
                        }
                    }
                }
                if (b7) {
                    for (; b4 < b3; b4++) {
                        b7(e[b4], b9, ca ? b8: b8.call(e[b4], b4, b7(e[b4], b9)))
                    }
                }
            }
        }
        return b5 ? e: b6 ? b7.call(e) : b3 ? b7(e[0], b9) : cb
    };
    var aK = (/^(?:checkbox|radio)$/i); (function() {
        var i = n.createElement("input"),
        b5 = n.createElement("div"),
        b3 = n.createDocumentFragment();
        b5.innerHTML = "  <link/><table></table><a href='/a'>a</a><input type='checkbox'/>";
        C.leadingWhitespace = b5.firstChild.nodeType === 3;
        C.tbody = !b5.getElementsByTagName("tbody").length;
        C.htmlSerialize = !!b5.getElementsByTagName("link").length;
        C.html5Clone = n.createElement("nav").cloneNode(true).outerHTML !== "<:nav></:nav>";
        i.type = "checkbox";
        i.checked = true;
        b3.appendChild(i);
        C.appendChecked = i.checked;
        b5.innerHTML = "<textarea>x</textarea>";
        C.noCloneChecked = !!b5.cloneNode(true).lastChild.defaultValue;
        b3.appendChild(b5);
        b5.innerHTML = "<input type='radio' checked='checked' name='t'/>";
        C.checkClone = b5.cloneNode(true).cloneNode(true).lastChild.checked;
        C.noCloneEvent = true;
        if (b5.attachEvent) {
            b5.attachEvent("onclick",
            function() {
                C.noCloneEvent = false
            });
            b5.cloneNode(true).click()
        }
        if (C.deleteExpando == null) {
            C.deleteExpando = true;
            try {
                delete b5.test
            } catch(b4) {
                C.deleteExpando = false
            }
        }
    })(); (function() {
        var b3, e, b4 = n.createElement("div");
        for (b3 in {
            submit: true,
            change: true,
            focusin: true
        }) {
            e = "on" + b3;
            if (! (C[b3 + "Bubbles"] = e in a3)) {
                b4.setAttribute(e, "t");
                C[b3 + "Bubbles"] = b4.attributes[e].expando === false
            }
        }
        b4 = null
    })();
    var bD = /^(?:input|select|textarea)$/i,
    a4 = /^key/,
    bJ = /^(?:mouse|pointer|contextmenu)|click/,
    bz = /^(?:focusinfocus|focusoutblur)$/,
    bu = /^([^.]*)(?:\.(.+)|)$/;
    function S() {
        return true
    }
    function X() {
        return false
    }
    function ak() {
        try {
            return n.activeElement
        } catch(e) {}
    }
    bF.event = {
        global: {},
        add: function(b5, ca, cf, b7, b6) {
            var b8, cg, ch, b3, cc, b9, ce, b4, cd, e, i, cb = bF._data(b5);
            if (!cb) {
                return
            }
            if (cf.handler) {
                b3 = cf;
                cf = b3.handler;
                b6 = b3.selector
            }
            if (!cf.guid) {
                cf.guid = bF.guid++
            }
            if (! (cg = cb.events)) {
                cg = cb.events = {}
            }
            if (! (b9 = cb.handle)) {
                b9 = cb.handle = function(ci) {
                    return typeof bF !== aA && (!ci || bF.event.triggered !== ci.type) ? bF.event.dispatch.apply(b9.elem, arguments) : undefined
                };
                b9.elem = b5
            }
            ca = (ca || "").match(aD) || [""];
            ch = ca.length;
            while (ch--) {
                b8 = bu.exec(ca[ch]) || [];
                cd = i = b8[1];
                e = (b8[2] || "").split(".").sort();
                if (!cd) {
                    continue
                }
                cc = bF.event.special[cd] || {};
                cd = (b6 ? cc.delegateType: cc.bindType) || cd;
                cc = bF.event.special[cd] || {};
                ce = bF.extend({
                    type: cd,
                    origType: i,
                    data: b7,
                    handler: cf,
                    guid: cf.guid,
                    selector: b6,
                    needsContext: b6 && bF.expr.match.needsContext.test(b6),
                    namespace: e.join(".")
                },
                b3);
                if (! (b4 = cg[cd])) {
                    b4 = cg[cd] = [];
                    b4.delegateCount = 0;
                    if (!cc.setup || cc.setup.call(b5, b7, e, b9) === false) {
                        if (b5.addEventListener) {
                            b5.addEventListener(cd, b9, false)
                        } else {
                            if (b5.attachEvent) {
                                b5.attachEvent("on" + cd, b9)
                            }
                        }
                    }
                }
                if (cc.add) {
                    cc.add.call(b5, ce);
                    if (!ce.handler.guid) {
                        ce.handler.guid = cf.guid
                    }
                }
                if (b6) {
                    b4.splice(b4.delegateCount++, 0, ce)
                } else {
                    b4.push(ce)
                }
                bF.event.global[cd] = true
            }
            b5 = null
        },
        remove: function(b4, ca, ch, b5, b9) {
            var b7, ce, b8, b6, cg, cf, cc, b3, cd, e, i, cb = bF.hasData(b4) && bF._data(b4);
            if (!cb || !(cf = cb.events)) {
                return
            }
            ca = (ca || "").match(aD) || [""];
            cg = ca.length;
            while (cg--) {
                b8 = bu.exec(ca[cg]) || [];
                cd = i = b8[1];
                e = (b8[2] || "").split(".").sort();
                if (!cd) {
                    for (cd in cf) {
                        bF.event.remove(b4, cd + ca[cg], ch, b5, true)
                    }
                    continue
                }
                cc = bF.event.special[cd] || {};
                cd = (b5 ? cc.delegateType: cc.bindType) || cd;
                b3 = cf[cd] || [];
                b8 = b8[2] && new RegExp("(^|\\.)" + e.join("\\.(?:.*\\.|)") + "(\\.|$)");
                b6 = b7 = b3.length;
                while (b7--) {
                    ce = b3[b7];
                    if ((b9 || i === ce.origType) && (!ch || ch.guid === ce.guid) && (!b8 || b8.test(ce.namespace)) && (!b5 || b5 === ce.selector || b5 === "**" && ce.selector)) {
                        b3.splice(b7, 1);
                        if (ce.selector) {
                            b3.delegateCount--
                        }
                        if (cc.remove) {
                            cc.remove.call(b4, ce)
                        }
                    }
                }
                if (b6 && !b3.length) {
                    if (!cc.teardown || cc.teardown.call(b4, e, cb.handle) === false) {
                        bF.removeEvent(b4, cd, cb.handle)
                    }
                    delete cf[cd]
                }
            }
            if (bF.isEmptyObject(cf)) {
                delete cb.handle;
                bF._removeData(b4, "events")
            }
        },
        trigger: function(b3, ca, b6, ch) {
            var cb, b5, cf, cg, cd, b9, b8, b7 = [b6 || n],
            ce = I.call(b3, "type") ? b3.type: b3,
            b4 = I.call(b3, "namespace") ? b3.namespace.split(".") : [];
            cf = b9 = b6 = b6 || n;
            if (b6.nodeType === 3 || b6.nodeType === 8) {
                return
            }
            if (bz.test(ce + bF.event.triggered)) {
                return
            }
            if (ce.indexOf(".") >= 0) {
                b4 = ce.split(".");
                ce = b4.shift();
                b4.sort()
            }
            b5 = ce.indexOf(":") < 0 && "on" + ce;
            b3 = b3[bF.expando] ? b3: new bF.Event(ce, typeof b3 === "object" && b3);
            b3.isTrigger = ch ? 2 : 3;
            b3.namespace = b4.join(".");
            b3.namespace_re = b3.namespace ? new RegExp("(^|\\.)" + b4.join("\\.(?:.*\\.|)") + "(\\.|$)") : null;
            b3.result = undefined;
            if (!b3.target) {
                b3.target = b6
            }
            ca = ca == null ? [b3] : bF.makeArray(ca, [b3]);
            cd = bF.event.special[ce] || {};
            if (!ch && cd.trigger && cd.trigger.apply(b6, ca) === false) {
                return
            }
            if (!ch && !cd.noBubble && !bF.isWindow(b6)) {
                cg = cd.delegateType || ce;
                if (!bz.test(cg + ce)) {
                    cf = cf.parentNode
                }
                for (; cf; cf = cf.parentNode) {
                    b7.push(cf);
                    b9 = cf
                }
                if (b9 === (b6.ownerDocument || n)) {
                    b7.push(b9.defaultView || b9.parentWindow || a3)
                }
            }
            b8 = 0;
            while ((cf = b7[b8++]) && !b3.isPropagationStopped()) {
                b3.type = b8 > 1 ? cg: cd.bindType || ce;
                cb = (bF._data(cf, "events") || {})[b3.type] && bF._data(cf, "handle");
                if (cb) {
                    cb.apply(cf, ca)
                }
                cb = b5 && cf[b5];
                if (cb && cb.apply && bF.acceptData(cf)) {
                    b3.result = cb.apply(cf, ca);
                    if (b3.result === false) {
                        b3.preventDefault()
                    }
                }
            }
            b3.type = ce;
            if (!ch && !b3.isDefaultPrevented()) {
                if ((!cd._default || cd._default.apply(b7.pop(), ca) === false) && bF.acceptData(b6)) {
                    if (b5 && b6[ce] && !bF.isWindow(b6)) {
                        b9 = b6[b5];
                        if (b9) {
                            b6[b5] = null
                        }
                        bF.event.triggered = ce;
                        try {
                            b6[ce]()
                        } catch(cc) {}
                        bF.event.triggered = undefined;
                        if (b9) {
                            b6[b5] = b9
                        }
                    }
                }
            }
            return b3.result
        },
        dispatch: function(e) {
            e = bF.event.fix(e);
            var b6, b7, cb, b3, b5, ca = [],
            b9 = N.call(arguments),
            b4 = (bF._data(this, "events") || {})[e.type] || [],
            b8 = bF.event.special[e.type] || {};
            b9[0] = e;
            e.delegateTarget = this;
            if (b8.preDispatch && b8.preDispatch.call(this, e) === false) {
                return
            }
            ca = bF.event.handlers.call(this, e, b4);
            b6 = 0;
            while ((b3 = ca[b6++]) && !e.isPropagationStopped()) {
                e.currentTarget = b3.elem;
                b5 = 0;
                while ((cb = b3.handlers[b5++]) && !e.isImmediatePropagationStopped()) {
                    if (!e.namespace_re || e.namespace_re.test(cb.namespace)) {
                        e.handleObj = cb;
                        e.data = cb.data;
                        b7 = ((bF.event.special[cb.origType] || {}).handle || cb.handler).apply(b3.elem, b9);
                        if (b7 !== undefined) {
                            if ((e.result = b7) === false) {
                                e.preventDefault();
                                e.stopPropagation()
                            }
                        }
                    }
                }
            }
            if (b8.postDispatch) {
                b8.postDispatch.call(this, e)
            }
            return e.result
        },
        handlers: function(e, b4) {
            var b3, b9, b7, b6, b8 = [],
            b5 = b4.delegateCount,
            ca = e.target;
            if (b5 && ca.nodeType && (!e.button || e.type !== "click")) {
                for (; ca != this; ca = ca.parentNode || this) {
                    if (ca.nodeType === 1 && (ca.disabled !== true || e.type !== "click")) {
                        b7 = [];
                        for (b6 = 0; b6 < b5; b6++) {
                            b9 = b4[b6];
                            b3 = b9.selector + " ";
                            if (b7[b3] === undefined) {
                                b7[b3] = b9.needsContext ? bF(b3, this).index(ca) >= 0 : bF.find(b3, this, null, [ca]).length
                            }
                            if (b7[b3]) {
                                b7.push(b9)
                            }
                        }
                        if (b7.length) {
                            b8.push({
                                elem: ca,
                                handlers: b7
                            })
                        }
                    }
                }
            }
            if (b5 < b4.length) {
                b8.push({
                    elem: this,
                    handlers: b4.slice(b5)
                })
            }
            return b8
        },
        fix: function(b5) {
            if (b5[bF.expando]) {
                return b5
            }
            var b3, b8, b7, b4 = b5.type,
            e = b5,
            b6 = this.fixHooks[b4];
            if (!b6) {
                this.fixHooks[b4] = b6 = bJ.test(b4) ? this.mouseHooks: a4.test(b4) ? this.keyHooks: {}
            }
            b7 = b6.props ? this.props.concat(b6.props) : this.props;
            b5 = new bF.Event(e);
            b3 = b7.length;
            while (b3--) {
                b8 = b7[b3];
                b5[b8] = e[b8]
            }
            if (!b5.target) {
                b5.target = e.srcElement || n
            }
            if (b5.target.nodeType === 3) {
                b5.target = b5.target.parentNode
            }
            b5.metaKey = !!b5.metaKey;
            return b6.filter ? b6.filter(b5, e) : b5
        },
        props: "altKey bubbles cancelable ctrlKey currentTarget eventPhase metaKey relatedTarget shiftKey target timeStamp view which".split(" "),
        fixHooks: {},
        keyHooks: {
            props: "char charCode key keyCode".split(" "),
            filter: function(i, e) {
                if (i.which == null) {
                    i.which = e.charCode != null ? e.charCode: e.keyCode
                }
                return i
            }
        },
        mouseHooks: {
            props: "button buttons clientX clientY fromElement offsetX offsetY pageX pageY screenX screenY toElement".split(" "),
            filter: function(b4, b3) {
                var e, b5, b6, i = b3.button,
                b7 = b3.fromElement;
                if (b4.pageX == null && b3.clientX != null) {
                    b5 = b4.target.ownerDocument || n;
                    b6 = b5.documentElement;
                    e = b5.body;
                    b4.pageX = b3.clientX + (b6 && b6.scrollLeft || e && e.scrollLeft || 0) - (b6 && b6.clientLeft || e && e.clientLeft || 0);
                    b4.pageY = b3.clientY + (b6 && b6.scrollTop || e && e.scrollTop || 0) - (b6 && b6.clientTop || e && e.clientTop || 0)
                }
                if (!b4.relatedTarget && b7) {
                    b4.relatedTarget = b7 === b4.target ? b3.toElement: b7
                }
                if (!b4.which && i !== undefined) {
                    b4.which = (i & 1 ? 1 : (i & 2 ? 3 : (i & 4 ? 2 : 0)))
                }
                return b4
            }
        },
        special: {
            load: {
                noBubble: true
            },
            focus: {
                trigger: function() {
                    if (this !== ak() && this.focus) {
                        try {
                            this.focus();
                            return false
                        } catch(i) {}
                    }
                },
                delegateType: "focusin"
            },
            blur: {
                trigger: function() {
                    if (this === ak() && this.blur) {
                        this.blur();
                        return false
                    }
                },
                delegateType: "focusout"
            },
            click: {
                trigger: function() {
                    if (bF.nodeName(this, "input") && this.type === "checkbox" && this.click) {
                        this.click();
                        return false
                    }
                },
                _default: function(e) {
                    return bF.nodeName(e.target, "a")
                }
            },
            beforeunload: {
                postDispatch: function(e) {
                    if (e.result !== undefined && e.originalEvent) {
                        e.originalEvent.returnValue = e.result
                    }
                }
            }
        },
        simulate: function(b3, b5, b4, i) {
            var b6 = bF.extend(new bF.Event(), b4, {
                type: b3,
                isSimulated: true,
                originalEvent: {}
            });
            if (i) {
                bF.event.trigger(b6, null, b5)
            } else {
                bF.event.dispatch.call(b5, b6)
            }
            if (b6.isDefaultPrevented()) {
                b4.preventDefault()
            }
        }
    };
    bF.removeEvent = n.removeEventListener ?
    function(i, e, b3) {
        if (i.removeEventListener) {
            i.removeEventListener(e, b3, false)
        }
    }: function(b3, i, b4) {
        var e = "on" + i;
        if (b3.detachEvent) {
            if (typeof b3[e] === aA) {
                b3[e] = null
            }
            b3.detachEvent(e, b4)
        }
    };
    bF.Event = function(i, e) {
        if (! (this instanceof bF.Event)) {
            return new bF.Event(i, e)
        }
        if (i && i.type) {
            this.originalEvent = i;
            this.type = i.type;
            this.isDefaultPrevented = i.defaultPrevented || i.defaultPrevented === undefined && i.returnValue === false ? S: X
        } else {
            this.type = i
        }
        if (e) {
            bF.extend(this, e)
        }
        this.timeStamp = i && i.timeStamp || bF.now();
        this[bF.expando] = true
    };
    bF.Event.prototype = {
        isDefaultPrevented: X,
        isPropagationStopped: X,
        isImmediatePropagationStopped: X,
        preventDefault: function() {
            var i = this.originalEvent;
            this.isDefaultPrevented = S;
            if (!i) {
                return
            }
            if (i.preventDefault) {
                i.preventDefault()
            } else {
                i.returnValue = false
            }
        },
        stopPropagation: function() {
            var i = this.originalEvent;
            this.isPropagationStopped = S;
            if (!i) {
                return
            }
            if (i.stopPropagation) {
                i.stopPropagation()
            }
            i.cancelBubble = true
        },
        stopImmediatePropagation: function() {
            var i = this.originalEvent;
            this.isImmediatePropagationStopped = S;
            if (i && i.stopImmediatePropagation) {
                i.stopImmediatePropagation()
            }
            this.stopPropagation()
        }
    };
    bF.each({
        mouseenter: "mouseover",
        mouseleave: "mouseout",
        pointerenter: "pointerover",
        pointerleave: "pointerout"
    },
    function(i, e) {
        bF.event.special[i] = {
            delegateType: e,
            bindType: e,
            handle: function(b5) {
                var b3, b7 = this,
                b6 = b5.relatedTarget,
                b4 = b5.handleObj;
                if (!b6 || (b6 !== b7 && !bF.contains(b7, b6))) {
                    b5.type = b4.origType;
                    b3 = b4.handler.apply(this, arguments);
                    b5.type = e
                }
                return b3
            }
        }
    });
    if (!C.submitBubbles) {
        bF.event.special.submit = {
            setup: function() {
                if (bF.nodeName(this, "form")) {
                    return false
                }
                bF.event.add(this, "click._submit keypress._submit",
                function(b4) {
                    var b3 = b4.target,
                    i = bF.nodeName(b3, "input") || bF.nodeName(b3, "button") ? b3.form: undefined;
                    if (i && !bF._data(i, "submitBubbles")) {
                        bF.event.add(i, "submit._submit",
                        function(e) {
                            e._submit_bubble = true
                        });
                        bF._data(i, "submitBubbles", true)
                    }
                })
            },
            postDispatch: function(e) {
                if (e._submit_bubble) {
                    delete e._submit_bubble;
                    if (this.parentNode && !e.isTrigger) {
                        bF.event.simulate("submit", this.parentNode, e, true)
                    }
                }
            },
            teardown: function() {
                if (bF.nodeName(this, "form")) {
                    return false
                }
                bF.event.remove(this, "._submit")
            }
        }
    }
    if (!C.changeBubbles) {
        bF.event.special.change = {
            setup: function() {
                if (bD.test(this.nodeName)) {
                    if (this.type === "checkbox" || this.type === "radio") {
                        bF.event.add(this, "propertychange._change",
                        function(e) {
                            if (e.originalEvent.propertyName === "checked") {
                                this._just_changed = true
                            }
                        });
                        bF.event.add(this, "click._change",
                        function(e) {
                            if (this._just_changed && !e.isTrigger) {
                                this._just_changed = false
                            }
                            bF.event.simulate("change", this, e, true)
                        })
                    }
                    return false
                }
                bF.event.add(this, "beforeactivate._change",
                function(b3) {
                    var i = b3.target;
                    if (bD.test(i.nodeName) && !bF._data(i, "changeBubbles")) {
                        bF.event.add(i, "change._change",
                        function(e) {
                            if (this.parentNode && !e.isSimulated && !e.isTrigger) {
                                bF.event.simulate("change", this.parentNode, e, true)
                            }
                        });
                        bF._data(i, "changeBubbles", true)
                    }
                })
            },
            handle: function(i) {
                var e = i.target;
                if (this !== e || i.isSimulated || i.isTrigger || (e.type !== "radio" && e.type !== "checkbox")) {
                    return i.handleObj.handler.apply(this, arguments)
                }
            },
            teardown: function() {
                bF.event.remove(this, "._change");
                return ! bD.test(this.nodeName)
            }
        }
    }
    if (!C.focusinBubbles) {
        bF.each({
            focus: "focusin",
            blur: "focusout"
        },
        function(b3, e) {
            var i = function(b4) {
                bF.event.simulate(e, b4.target, bF.event.fix(b4), true)
            };
            bF.event.special[e] = {
                setup: function() {
                    var b5 = this.ownerDocument || this,
                    b4 = bF._data(b5, e);
                    if (!b4) {
                        b5.addEventListener(b3, i, true)
                    }
                    bF._data(b5, e, (b4 || 0) + 1)
                },
                teardown: function() {
                    var b5 = this.ownerDocument || this,
                    b4 = bF._data(b5, e) - 1;
                    if (!b4) {
                        b5.removeEventListener(b3, i, true);
                        bF._removeData(b5, e)
                    } else {
                        bF._data(b5, e, b4)
                    }
                }
            }
        })
    }
    bF.fn.extend({
        on: function(b3, e, b6, b5, i) {
            var b4, b7;
            if (typeof b3 === "object") {
                if (typeof e !== "string") {
                    b6 = b6 || e;
                    e = undefined
                }
                for (b4 in b3) {
                    this.on(b4, e, b6, b3[b4], i)
                }
                return this
            }
            if (b6 == null && b5 == null) {
                b5 = e;
                b6 = e = undefined
            } else {
                if (b5 == null) {
                    if (typeof e === "string") {
                        b5 = b6;
                        b6 = undefined
                    } else {
                        b5 = b6;
                        b6 = e;
                        e = undefined
                    }
                }
            }
            if (b5 === false) {
                b5 = X
            } else {
                if (!b5) {
                    return this
                }
            }
            if (i === 1) {
                b7 = b5;
                b5 = function(b8) {
                    bF().off(b8);
                    return b7.apply(this, arguments)
                };
                b5.guid = b7.guid || (b7.guid = bF.guid++)
            }
            return this.each(function() {
                bF.event.add(this, b3, b5, b6, e)
            })
        },
        one: function(i, e, b4, b3) {
            return this.on(i, e, b4, b3, 1)
        },
        off: function(b3, e, b5) {
            var i, b4;
            if (b3 && b3.preventDefault && b3.handleObj) {
                i = b3.handleObj;
                bF(b3.delegateTarget).off(i.namespace ? i.origType + "." + i.namespace: i.origType, i.selector, i.handler);
                return this
            }
            if (typeof b3 === "object") {
                for (b4 in b3) {
                    this.off(b4, e, b3[b4])
                }
                return this
            }
            if (e === false || typeof e === "function") {
                b5 = e;
                e = undefined
            }
            if (b5 === false) {
                b5 = X
            }
            return this.each(function() {
                bF.event.remove(this, b3, b5, e)
            })
        },
        trigger: function(e, i) {
            return this.each(function() {
                bF.event.trigger(e, i, this)
            })
        },
        triggerHandler: function(e, b3) {
            var i = this[0];
            if (i) {
                return bF.event.trigger(e, b3, i, true)
            }
        }
    });
    function A(e) {
        var b3 = d.split("|"),
        i = e.createDocumentFragment();
        if (i.createElement) {
            while (b3.length) {
                i.createElement(b3.pop())
            }
        }
        return i
    }
    var d = "abbr|article|aside|audio|bdi|canvas|data|datalist|details|figcaption|figure|footer|header|hgroup|mark|meter|nav|output|progress|section|summary|time|video",
    aB = / jQuery\d+="(?:null|\d+)"/g,
    K = new RegExp("<(?:" + d + ")[\\s/>]", "i"),
    b2 = /^\s+/,
    aF = /<(?!area|br|col|embed|hr|img|input|link|meta|param)(([\w:]+)[^>]*)\/>/gi,
    o = /<([\w:]+)/,
    bX = /<tbody/i,
    J = /<|&#?\w+;/,
    al = /<(?:script|style|link)/i,
    bT = /checked\s*(?:[^=]|=\s*.checked.)/i,
    by = /^$|\/(?:java|ecma)script/i,
    ap = /^true\/(.*)/,
    aM = /^\s*<!(?:\[CDATA\[|--)|(?:\]\]|--)>\s*$/g,
    U = {
        option: [1, "<select multiple='multiple'>", "</select>"],
        legend: [1, "<fieldset>", "</fieldset>"],
        area: [1, "<map>", "</map>"],
        param: [1, "<object>", "</object>"],
        thead: [1, "<table>", "</table>"],
        tr: [2, "<table><tbody>", "</tbody></table>"],
        col: [2, "<table><tbody></tbody><colgroup>", "</colgroup></table>"],
        td: [3, "<table><tbody><tr>", "</tr></tbody></table>"],
        _default: C.htmlSerialize ? [0, "", ""] : [1, "X<div>", "</div>"]
    },
    aR = A(n),
    k = aR.appendChild(n.createElement("div"));
    U.optgroup = U.option;
    U.tbody = U.tfoot = U.colgroup = U.caption = U.thead;
    U.th = U.td;
    function l(b5, e) {
        var b3, b6, b4 = 0,
        b7 = typeof b5.getElementsByTagName !== aA ? b5.getElementsByTagName(e || "*") : typeof b5.querySelectorAll !== aA ? b5.querySelectorAll(e || "*") : undefined;
        if (!b7) {
            for (b7 = [], b3 = b5.childNodes || b5; (b6 = b3[b4]) != null; b4++) {
                if (!e || bF.nodeName(b6, e)) {
                    b7.push(b6)
                } else {
                    bF.merge(b7, l(b6, e))
                }
            }
        }
        return e === undefined || e && bF.nodeName(b5, e) ? bF.merge([b5], b7) : b7
    }
    function bV(e) {
        if (aK.test(e.type)) {
            e.defaultChecked = e.checked
        }
    }
    function a1(i, e) {
        return bF.nodeName(i, "table") && bF.nodeName(e.nodeType !== 11 ? e: e.firstChild, "tr") ? i.getElementsByTagName("tbody")[0] || i.appendChild(i.ownerDocument.createElement("tbody")) : i
    }
    function t(e) {
        e.type = (bF.find.attr(e, "type") !== null) + "/" + e.type;
        return e
    }
    function bd(i) {
        var e = ap.exec(i.type);
        if (e) {
            i.type = e[1]
        } else {
            i.removeAttribute("type")
        }
        return i
    }
    function br(e, b4) {
        var b5, b3 = 0;
        for (; (b5 = e[b3]) != null; b3++) {
            bF._data(b5, "globalEval", !b4 || bF._data(b4[b3], "globalEval"))
        }
    }
    function aq(b9, b3) {
        if (b3.nodeType !== 1 || !bF.hasData(b9)) {
            return
        }
        var b6, b5, e, b8 = bF._data(b9),
        b7 = bF._data(b3, b8),
        b4 = b8.events;
        if (b4) {
            delete b7.handle;
            b7.events = {};
            for (b6 in b4) {
                for (b5 = 0, e = b4[b6].length; b5 < e; b5++) {
                    bF.event.add(b3, b6, b4[b6][b5])
                }
            }
        }
        if (b7.data) {
            b7.data = bF.extend({},
            b7.data)
        }
    }
    function R(b5, i) {
        var b6, b4, b3;
        if (i.nodeType !== 1) {
            return
        }
        b6 = i.nodeName.toLowerCase();
        if (!C.noCloneEvent && i[bF.expando]) {
            b3 = bF._data(i);
            for (b4 in b3.events) {
                bF.removeEvent(i, b4, b3.handle)
            }
            i.removeAttribute(bF.expando)
        }
        if (b6 === "script" && i.text !== b5.text) {
            t(i).text = b5.text;
            bd(i)
        } else {
            if (b6 === "object") {
                if (i.parentNode) {
                    i.outerHTML = b5.outerHTML
                }
                if (C.html5Clone && (b5.innerHTML && !bF.trim(i.innerHTML))) {
                    i.innerHTML = b5.innerHTML
                }
            } else {
                if (b6 === "input" && aK.test(b5.type)) {
                    i.defaultChecked = i.checked = b5.checked;
                    if (i.value !== b5.value) {
                        i.value = b5.value
                    }
                } else {
                    if (b6 === "option") {
                        i.defaultSelected = i.selected = b5.defaultSelected
                    } else {
                        if (b6 === "input" || b6 === "textarea") {
                            i.defaultValue = b5.defaultValue
                        }
                    }
                }
            }
        }
    }
    bF.extend({
        clone: function(b3, b5, e) {
            var b7, b4, ca, b6, b8, b9 = bF.contains(b3.ownerDocument, b3);
            if (C.html5Clone || bF.isXMLDoc(b3) || !K.test("<" + b3.nodeName + ">")) {
                ca = b3.cloneNode(true)
            } else {
                k.innerHTML = b3.outerHTML;
                k.removeChild(ca = k.firstChild)
            }
            if ((!C.noCloneEvent || !C.noCloneChecked) && (b3.nodeType === 1 || b3.nodeType === 11) && !bF.isXMLDoc(b3)) {
                b7 = l(ca);
                b8 = l(b3);
                for (b6 = 0; (b4 = b8[b6]) != null; ++b6) {
                    if (b7[b6]) {
                        R(b4, b7[b6])
                    }
                }
            }
            if (b5) {
                if (e) {
                    b8 = b8 || l(b3);
                    b7 = b7 || l(ca);
                    for (b6 = 0; (b4 = b8[b6]) != null; b6++) {
                        aq(b4, b7[b6])
                    }
                } else {
                    aq(b3, ca)
                }
            }
            b7 = l(ca, "script");
            if (b7.length > 0) {
                br(b7, !b9 && l(b3, "script"))
            }
            b7 = b8 = b4 = null;
            return ca
        },
        buildFragment: function(b3, b5, ca, cf) {
            var cb, b7, b9, ce, cg, cd, b4, b8 = b3.length,
            b6 = A(b5),
            e = [],
            cc = 0;
            for (; cc < b8; cc++) {
                b7 = b3[cc];
                if (b7 || b7 === 0) {
                    if (bF.type(b7) === "object") {
                        bF.merge(e, b7.nodeType ? [b7] : b7)
                    } else {
                        if (!J.test(b7)) {
                            e.push(b5.createTextNode(b7))
                        } else {
                            ce = ce || b6.appendChild(b5.createElement("div"));
                            cg = (o.exec(b7) || ["", ""])[1].toLowerCase();
                            b4 = U[cg] || U._default;
                            ce.innerHTML = b4[1] + b7.replace(aF, "<$1></$2>") + b4[2];
                            cb = b4[0];
                            while (cb--) {
                                ce = ce.lastChild
                            }
                            if (!C.leadingWhitespace && b2.test(b7)) {
                                e.push(b5.createTextNode(b2.exec(b7)[0]))
                            }
                            if (!C.tbody) {
                                b7 = cg === "table" && !bX.test(b7) ? ce.firstChild: b4[1] === "<table>" && !bX.test(b7) ? ce: 0;
                                cb = b7 && b7.childNodes.length;
                                while (cb--) {
                                    if (bF.nodeName((cd = b7.childNodes[cb]), "tbody") && !cd.childNodes.length) {
                                        b7.removeChild(cd)
                                    }
                                }
                            }
                            bF.merge(e, ce.childNodes);
                            ce.textContent = "";
                            while (ce.firstChild) {
                                ce.removeChild(ce.firstChild)
                            }
                            ce = b6.lastChild
                        }
                    }
                }
            }
            if (ce) {
                b6.removeChild(ce)
            }
            if (!C.appendChecked) {
                bF.grep(l(e, "input"), bV)
            }
            cc = 0;
            while ((b7 = e[cc++])) {
                if (cf && bF.inArray(b7, cf) !== -1) {
                    continue
                }
                b9 = bF.contains(b7.ownerDocument, b7);
                ce = l(b6.appendChild(b7), "script");
                if (b9) {
                    br(ce)
                }
                if (ca) {
                    cb = 0;
                    while ((b7 = ce[cb++])) {
                        if (by.test(b7.type || "")) {
                            ca.push(b7)
                        }
                    }
                }
            }
            ce = null;
            return b6
        },
        cleanData: function(b3, cb) {
            var b5, ca, b4, b6, b7 = 0,
            cc = bF.expando,
            e = bF.cache,
            b8 = C.deleteExpando,
            b9 = bF.event.special;
            for (; (b5 = b3[b7]) != null; b7++) {
                if (cb || bF.acceptData(b5)) {
                    b4 = b5[cc];
                    b6 = b4 && e[b4];
                    if (b6) {
                        if (b6.events) {
                            for (ca in b6.events) {
                                if (b9[ca]) {
                                    bF.event.remove(b5, ca)
                                } else {
                                    bF.removeEvent(b5, ca, b6.handle)
                                }
                            }
                        }
                        if (e[b4]) {
                            delete e[b4];
                            if (b8) {
                                delete b5[cc]
                            } else {
                                if (typeof b5.removeAttribute !== aA) {
                                    b5.removeAttribute(cc)
                                } else {
                                    b5[cc] = null
                                }
                            }
                            aN.push(b4)
                        }
                    }
                }
            }
        }
    });
    bF.fn.extend({
        text: function(e) {
            return az(this,
            function(i) {
                return i === undefined ? bF.text(this) : this.empty().append((this[0] && this[0].ownerDocument || n).createTextNode(i))
            },
            null, e, arguments.length)
        },
        append: function() {
            return this.domManip(arguments,
            function(e) {
                if (this.nodeType === 1 || this.nodeType === 11 || this.nodeType === 9) {
                    var i = a1(this, e);
                    i.appendChild(e)
                }
            })
        },
        prepend: function() {
            return this.domManip(arguments,
            function(e) {
                if (this.nodeType === 1 || this.nodeType === 11 || this.nodeType === 9) {
                    var i = a1(this, e);
                    i.insertBefore(e, i.firstChild)
                }
            })
        },
        before: function() {
            return this.domManip(arguments,
            function(e) {
                if (this.parentNode) {
                    this.parentNode.insertBefore(e, this)
                }
            })
        },
        after: function() {
            return this.domManip(arguments,
            function(e) {
                if (this.parentNode) {
                    this.parentNode.insertBefore(e, this.nextSibling)
                }
            })
        },
        remove: function(e, b6) {
            var b5, b3 = e ? bF.filter(e, this) : this,
            b4 = 0;
            for (; (b5 = b3[b4]) != null; b4++) {
                if (!b6 && b5.nodeType === 1) {
                    bF.cleanData(l(b5))
                }
                if (b5.parentNode) {
                    if (b6 && bF.contains(b5.ownerDocument, b5)) {
                        br(l(b5, "script"))
                    }
                    b5.parentNode.removeChild(b5)
                }
            }
            return this
        },
        empty: function() {
            var b3, e = 0;
            for (; (b3 = this[e]) != null; e++) {
                if (b3.nodeType === 1) {
                    bF.cleanData(l(b3, false))
                }
                while (b3.firstChild) {
                    b3.removeChild(b3.firstChild)
                }
                if (b3.options && bF.nodeName(b3, "select")) {
                    b3.options.length = 0
                }
            }
            return this
        },
        clone: function(i, e) {
            i = i == null ? false: i;
            e = e == null ? i: e;
            return this.map(function() {
                return bF.clone(this, i, e)
            })
        },
        html: function(e) {
            return az(this,
            function(b6) {
                var b5 = this[0] || {},
                b4 = 0,
                b3 = this.length;
                if (b6 === undefined) {
                    return b5.nodeType === 1 ? b5.innerHTML.replace(aB, "") : undefined
                }
                if (typeof b6 === "string" && !al.test(b6) && (C.htmlSerialize || !K.test(b6)) && (C.leadingWhitespace || !b2.test(b6)) && !U[(o.exec(b6) || ["", ""])[1].toLowerCase()]) {
                    b6 = b6.replace(aF, "<$1></$2>");
                    try {
                        for (; b4 < b3; b4++) {
                            b5 = this[b4] || {};
                            if (b5.nodeType === 1) {
                                bF.cleanData(l(b5, false));
                                b5.innerHTML = b6
                            }
                        }
                        b5 = 0
                    } catch(b7) {}
                }
                if (b5) {
                    this.empty().append(b6)
                }
            },
            null, e, arguments.length)
        },
        replaceWith: function() {
            var e = arguments[0];
            this.domManip(arguments,
            function(i) {
                e = this.parentNode;
                bF.cleanData(l(this));
                if (e) {
                    e.replaceChild(i, this)
                }
            });
            return e && (e.length || e.nodeType) ? this: this.remove()
        },
        detach: function(e) {
            return this.remove(e, true)
        },
        domManip: function(ca, cf) {
            ca = ax.apply([], ca);
            var b8, b4, e, b6, cd, b9, b7 = 0,
            b5 = this.length,
            cc = this,
            ce = b5 - 1,
            cb = ca[0],
            b3 = bF.isFunction(cb);
            if (b3 || (b5 > 1 && typeof cb === "string" && !C.checkClone && bT.test(cb))) {
                return this.each(function(cg) {
                    var i = cc.eq(cg);
                    if (b3) {
                        ca[0] = cb.call(this, cg, i.html())
                    }
                    i.domManip(ca, cf)
                })
            }
            if (b5) {
                b9 = bF.buildFragment(ca, this[0].ownerDocument, false, this);
                b8 = b9.firstChild;
                if (b9.childNodes.length === 1) {
                    b9 = b8
                }
                if (b8) {
                    b6 = bF.map(l(b9, "script"), t);
                    e = b6.length;
                    for (; b7 < b5; b7++) {
                        b4 = b9;
                        if (b7 !== ce) {
                            b4 = bF.clone(b4, true, true);
                            if (e) {
                                bF.merge(b6, l(b4, "script"))
                            }
                        }
                        cf.call(this[b7], b4, b7)
                    }
                    if (e) {
                        cd = b6[b6.length - 1].ownerDocument;
                        bF.map(b6, bd);
                        for (b7 = 0; b7 < e; b7++) {
                            b4 = b6[b7];
                            if (by.test(b4.type || "") && !bF._data(b4, "globalEval") && bF.contains(cd, b4)) {
                                if (b4.src) {
                                    if (bF._evalUrl) {
                                        bF._evalUrl(b4.src)
                                    }
                                } else {
                                    bF.globalEval((b4.text || b4.textContent || b4.innerHTML || "").replace(aM, ""))
                                }
                            }
                        }
                    }
                    b9 = b8 = null
                }
            }
            return this
        }
    });
    bF.each({
        appendTo: "append",
        prependTo: "prepend",
        insertBefore: "before",
        insertAfter: "after",
        replaceAll: "replaceWith"
    },
    function(e, i) {
        bF.fn[e] = function(b3) {
            var b4, b6 = 0,
            b5 = [],
            b8 = bF(b3),
            b7 = b8.length - 1;
            for (; b6 <= b7; b6++) {
                b4 = b6 === b7 ? this: this.clone(true);
                bF(b8[b6])[i](b4);
                w.apply(b5, b4.get())
            }
            return this.pushStack(b5)
        }
    });
    var aG, bi = {};
    function a2(e, b5) {
        var i, b3 = bF(b5.createElement(e)).appendTo(b5.body),
        b4 = a3.getDefaultComputedStyle && (i = a3.getDefaultComputedStyle(b3[0])) ? i.display: bF.css(b3[0], "display");
        b3.detach();
        return b4
    }
    function aY(b3) {
        var i = n,
        e = bi[b3];
        if (!e) {
            e = a2(b3, i);
            if (e === "none" || !e) {
                aG = (aG || bF("<iframe frameborder='0' width='0' height='0'/>")).appendTo(i.documentElement);
                i = (aG[0].contentWindow || aG[0].contentDocument).document;
                i.write();
                i.close();
                e = a2(b3, i);
                aG.detach()
            }
            bi[b3] = e
        }
        return e
    } (function() {
        var e;
        C.shrinkWrapBlocks = function() {
            if (e != null) {
                return e
            }
            e = false;
            var b4, i, b3;
            i = n.getElementsByTagName("body")[0];
            if (!i || !i.style) {
                return
            }
            b4 = n.createElement("div");
            b3 = n.createElement("div");
            b3.style.cssText = "position:absolute;border:0;width:0;height:0;top:0;left:-9999px";
            i.appendChild(b3).appendChild(b4);
            if (typeof b4.style.zoom !== aA) {
                b4.style.cssText = "-webkit-box-sizing:content-box;-moz-box-sizing:content-box;box-sizing:content-box;display:block;margin:0;border:0;padding:1px;width:1px;zoom:1";
                b4.appendChild(n.createElement("div")).style.width = "5px";
                e = b4.offsetWidth !== 3
            }
            i.removeChild(b3);
            return e
        }
    })();
    var aX = (/^margin/);
    var W = new RegExp("^(" + aC + ")(?!px)[a-z%]+$", "i");
    var bn, F, bl = /^(top|right|bottom|left)$/;
    if (a3.getComputedStyle) {
        bn = function(e) {
            return e.ownerDocument.defaultView.getComputedStyle(e, null)
        };
        F = function(b8, i, b7) {
            var b5, b4, b6, e, b3 = b8.style;
            b7 = b7 || bn(b8);
            e = b7 ? b7.getPropertyValue(i) || b7[i] : undefined;
            if (b7) {
                if (e === "" && !bF.contains(b8.ownerDocument, b8)) {
                    e = bF.style(b8, i)
                }
                if (W.test(e) && aX.test(i)) {
                    b5 = b3.width;
                    b4 = b3.minWidth;
                    b6 = b3.maxWidth;
                    b3.minWidth = b3.maxWidth = b3.width = e;
                    e = b7.width;
                    b3.width = b5;
                    b3.minWidth = b4;
                    b3.maxWidth = b6
                }
            }
            return e === undefined ? e: e + ""
        }
    } else {
        if (n.documentElement.currentStyle) {
            bn = function(e) {
                return e.currentStyle
            };
            F = function(b7, b4, b6) {
                var b8, i, e, b3, b5 = b7.style;
                b6 = b6 || bn(b7);
                b3 = b6 ? b6[b4] : undefined;
                if (b3 == null && b5 && b5[b4]) {
                    b3 = b5[b4]
                }
                if (W.test(b3) && !bl.test(b4)) {
                    b8 = b5.left;
                    i = b7.runtimeStyle;
                    e = i && i.left;
                    if (e) {
                        i.left = b7.currentStyle.left
                    }
                    b5.left = b4 === "fontSize" ? "1em": b3;
                    b3 = b5.pixelLeft + "px";
                    b5.left = b8;
                    if (e) {
                        i.left = e
                    }
                }
                return b3 === undefined ? b3: b3 + "" || "auto"
            }
        }
    }
    function a5(e, i) {
        return {
            get: function() {
                var b3 = e();
                if (b3 == null) {
                    return
                }
                if (b3) {
                    delete this.get;
                    return
                }
                return (this.get = i).apply(this, arguments)
            }
        }
    } (function() {
        var b8, b6, b4, b7, b3, b5, i;
        b8 = n.createElement("div");
        b8.innerHTML = "  <link/><table></table><a href='/a'>a</a><input type='checkbox'/>";
        b4 = b8.getElementsByTagName("a")[0];
        b6 = b4 && b4.style;
        if (!b6) {
            return
        }
        b6.cssText = "float:left;opacity:.5";
        C.opacity = b6.opacity === "0.5";
        C.cssFloat = !!b6.cssFloat;
        b8.style.backgroundClip = "content-box";
        b8.cloneNode(true).style.backgroundClip = "";
        C.clearCloneStyle = b8.style.backgroundClip === "content-box";
        C.boxSizing = b6.boxSizing === "" || b6.MozBoxSizing === "" || b6.WebkitBoxSizing === "";
        bF.extend(C, {
            reliableHiddenOffsets: function() {
                if (b5 == null) {
                    e()
                }
                return b5
            },
            boxSizingReliable: function() {
                if (b3 == null) {
                    e()
                }
                return b3
            },
            pixelPosition: function() {
                if (b7 == null) {
                    e()
                }
                return b7
            },
            reliableMarginRight: function() {
                if (i == null) {
                    e()
                }
                return i
            }
        });
        function e() {
            var cc, b9, ca, cb;
            b9 = n.getElementsByTagName("body")[0];
            if (!b9 || !b9.style) {
                return
            }
            cc = n.createElement("div");
            ca = n.createElement("div");
            ca.style.cssText = "position:absolute;border:0;width:0;height:0;top:0;left:-9999px";
            b9.appendChild(ca).appendChild(cc);
            cc.style.cssText = "-webkit-box-sizing:border-box;-moz-box-sizing:border-box;box-sizing:border-box;display:block;margin-top:1%;top:1%;border:1px;padding:1px;width:4px;position:absolute";
            b7 = b3 = false;
            i = true;
            if (a3.getComputedStyle) {
                b7 = (a3.getComputedStyle(cc, null) || {}).top !== "1%";
                b3 = (a3.getComputedStyle(cc, null) || {
                    width: "4px"
                }).width === "4px";
                cb = cc.appendChild(n.createElement("div"));
                cb.style.cssText = cc.style.cssText = "-webkit-box-sizing:content-box;-moz-box-sizing:content-box;box-sizing:content-box;display:block;margin:0;border:0;padding:0";
                cb.style.marginRight = cb.style.width = "0";
                cc.style.width = "1px";
                i = !parseFloat((a3.getComputedStyle(cb, null) || {}).marginRight)
            }
            cc.innerHTML = "<table><tr><td></td><td>t</td></tr></table>";
            cb = cc.getElementsByTagName("td");
            cb[0].style.cssText = "margin:0;border:0;padding:0;display:none";
            b5 = cb[0].offsetHeight === 0;
            if (b5) {
                cb[0].style.display = "";
                cb[1].style.display = "none";
                b5 = cb[0].offsetHeight === 0
            }
            b9.removeChild(ca)
        }
    })();
    bF.swap = function(b6, b5, b7, b4) {
        var b3, i, e = {};
        for (i in b5) {
            e[i] = b6.style[i];
            b6.style[i] = b5[i]
        }
        b3 = b7.apply(b6, b4 || []);
        for (i in b5) {
            b6.style[i] = e[i]
        }
        return b3
    };
    var bh = /alpha\([^)]*\)/i,
    aS = /opacity\s*=\s*([^)]*)/,
    G = /^(none|table(?!-c[ea]).+)/,
    a9 = new RegExp("^(" + aC + ")(.*)$", "i"),
    T = new RegExp("^([+-])=(" + aC + ")", "i"),
    bc = {
        position: "absolute",
        visibility: "hidden",
        display: "block"
    },
    bA = {
        letterSpacing: "0",
        fontWeight: "400"
    },
    au = ["Webkit", "O", "Moz", "ms"];
    function c(b5, b3) {
        if (b3 in b5) {
            return b3
        }
        var b6 = b3.charAt(0).toUpperCase() + b3.slice(1),
        e = b3,
        b4 = au.length;
        while (b4--) {
            b3 = au[b4] + b6;
            if (b3 in b5) {
                return b3
            }
        }
        return e
    }
    function r(b7, e) {
        var b8, b5, b6, i = [],
        b3 = 0,
        b4 = b7.length;
        for (; b3 < b4; b3++) {
            b5 = b7[b3];
            if (!b5.style) {
                continue
            }
            i[b3] = bF._data(b5, "olddisplay");
            b8 = b5.style.display;
            if (e) {
                if (!i[b3] && b8 === "none") {
                    b5.style.display = ""
                }
                if (b5.style.display === "" && Q(b5)) {
                    i[b3] = bF._data(b5, "olddisplay", aY(b5.nodeName))
                }
            } else {
                b6 = Q(b5);
                if (b8 && b8 !== "none" || !b6) {
                    bF._data(b5, "olddisplay", b6 ? b8: bF.css(b5, "display"))
                }
            }
        }
        for (b3 = 0; b3 < b4; b3++) {
            b5 = b7[b3];
            if (!b5.style) {
                continue
            }
            if (!e || b5.style.display === "none" || b5.style.display === "") {
                b5.style.display = e ? i[b3] || "": "none"
            }
        }
        return b7
    }
    function aL(e, b3, b4) {
        var i = a9.exec(b3);
        return i ? Math.max(0, i[1] - (b4 || 0)) + (i[2] || "px") : b3
    }
    function av(b6, b3, e, b8, b5) {
        var b4 = e === (b8 ? "border": "content") ? 4 : b3 === "width" ? 1 : 0,
        b7 = 0;
        for (; b4 < 4; b4 += 2) {
            if (e === "margin") {
                b7 += bF.css(b6, e + bQ[b4], true, b5)
            }
            if (b8) {
                if (e === "content") {
                    b7 -= bF.css(b6, "padding" + bQ[b4], true, b5)
                }
                if (e !== "margin") {
                    b7 -= bF.css(b6, "border" + bQ[b4] + "Width", true, b5)
                }
            } else {
                b7 += bF.css(b6, "padding" + bQ[b4], true, b5);
                if (e !== "padding") {
                    b7 += bF.css(b6, "border" + bQ[b4] + "Width", true, b5)
                }
            }
        }
        return b7
    }
    function u(b5, i, e) {
        var b4 = true,
        b6 = i === "width" ? b5.offsetWidth: b5.offsetHeight,
        b3 = bn(b5),
        b7 = C.boxSizing && bF.css(b5, "boxSizing", false, b3) === "border-box";
        if (b6 <= 0 || b6 == null) {
            b6 = F(b5, i, b3);
            if (b6 < 0 || b6 == null) {
                b6 = b5.style[i]
            }
            if (W.test(b6)) {
                return b6
            }
            b4 = b7 && (C.boxSizingReliable() || b6 === b5.style[i]);
            b6 = parseFloat(b6) || 0
        }
        return (b6 + av(b5, i, e || (b7 ? "border": "content"), b4, b3)) + "px"
    }
    bF.extend({
        cssHooks: {
            opacity: {
                get: function(b3, i) {
                    if (i) {
                        var e = F(b3, "opacity");
                        return e === "" ? "1": e
                    }
                }
            }
        },
        cssNumber: {
            columnCount: true,
            fillOpacity: true,
            flexGrow: true,
            flexShrink: true,
            fontWeight: true,
            lineHeight: true,
            opacity: true,
            order: true,
            orphans: true,
            widows: true,
            zIndex: true,
            zoom: true
        },
        cssProps: {
            "float": C.cssFloat ? "cssFloat": "styleFloat"
        },
        style: function(b4, b3, ca, b5) {
            if (!b4 || b4.nodeType === 3 || b4.nodeType === 8 || !b4.style) {
                return
            }
            var b8, b9, cb, b6 = bF.camelCase(b3),
            i = b4.style;
            b3 = bF.cssProps[b6] || (bF.cssProps[b6] = c(i, b6));
            cb = bF.cssHooks[b3] || bF.cssHooks[b6];
            if (ca !== undefined) {
                b9 = typeof ca;
                if (b9 === "string" && (b8 = T.exec(ca))) {
                    ca = (b8[1] + 1) * b8[2] + parseFloat(bF.css(b4, b3));
                    b9 = "number"
                }
                if (ca == null || ca !== ca) {
                    return
                }
                if (b9 === "number" && !bF.cssNumber[b6]) {
                    ca += "px"
                }
                if (!C.clearCloneStyle && ca === "" && b3.indexOf("background") === 0) {
                    i[b3] = "inherit"
                }
                if (!cb || !("set" in cb) || (ca = cb.set(b4, ca, b5)) !== undefined) {
                    try {
                        i[b3] = ca
                    } catch(b7) {}
                }
            } else {
                if (cb && "get" in cb && (b8 = cb.get(b4, false, b5)) !== undefined) {
                    return b8
                }
                return i[b3]
            }
        },
        css: function(b7, b5, i, b6) {
            var b4, b8, e, b3 = bF.camelCase(b5);
            b5 = bF.cssProps[b3] || (bF.cssProps[b3] = c(b7.style, b3));
            e = bF.cssHooks[b5] || bF.cssHooks[b3];
            if (e && "get" in e) {
                b8 = e.get(b7, true, i)
            }
            if (b8 === undefined) {
                b8 = F(b7, b5, b6)
            }
            if (b8 === "normal" && b5 in bA) {
                b8 = bA[b5]
            }
            if (i === "" || i) {
                b4 = parseFloat(b8);
                return i === true || bF.isNumeric(b4) ? b4 || 0 : b8
            }
            return b8
        }
    });
    bF.each(["height", "width"],
    function(b3, e) {
        bF.cssHooks[e] = {
            get: function(b5, b4, i) {
                if (b4) {
                    return G.test(bF.css(b5, "display")) && b5.offsetWidth === 0 ? bF.swap(b5, bc,
                    function() {
                        return u(b5, e, i)
                    }) : u(b5, e, i)
                }
            },
            set: function(b5, b6, i) {
                var b4 = i && bn(b5);
                return aL(b5, b6, i ? av(b5, e, i, C.boxSizing && bF.css(b5, "boxSizing", false, b4) === "border-box", b4) : 0)
            }
        }
    });
    if (!C.opacity) {
        bF.cssHooks.opacity = {
            get: function(i, e) {
                return aS.test((e && i.currentStyle ? i.currentStyle.filter: i.style.filter) || "") ? (0.01 * parseFloat(RegExp.$1)) + "": e ? "1": ""
            },
            set: function(b5, b6) {
                var b4 = b5.style,
                i = b5.currentStyle,
                e = bF.isNumeric(b6) ? "alpha(opacity=" + b6 * 100 + ")": "",
                b3 = i && i.filter || b4.filter || "";
                b4.zoom = 1;
                if ((b6 >= 1 || b6 === "") && bF.trim(b3.replace(bh, "")) === "" && b4.removeAttribute) {
                    b4.removeAttribute("filter");
                    if (b6 === "" || i && !i.filter) {
                        return
                    }
                }
                b4.filter = bh.test(b3) ? b3.replace(bh, e) : b3 + " " + e
            }
        }
    }
    bF.cssHooks.marginRight = a5(C.reliableMarginRight,
    function(i, e) {
        if (e) {
            return bF.swap(i, {
                display: "inline-block"
            },
            F, [i, "marginRight"])
        }
    });
    bF.each({
        margin: "",
        padding: "",
        border: "Width"
    },
    function(e, i) {
        bF.cssHooks[e + i] = {
            expand: function(b5) {
                var b4 = 0,
                b3 = {},
                b6 = typeof b5 === "string" ? b5.split(" ") : [b5];
                for (; b4 < 4; b4++) {
                    b3[e + bQ[b4] + i] = b6[b4] || b6[b4 - 2] || b6[0]
                }
                return b3
            }
        };
        if (!aX.test(e)) {
            bF.cssHooks[e + i].set = aL
        }
    });
    bF.fn.extend({
        css: function(e, i) {
            return az(this,
            function(b7, b4, b8) {
                var b6, b3, b9 = {},
                b5 = 0;
                if (bF.isArray(b4)) {
                    b6 = bn(b7);
                    b3 = b4.length;
                    for (; b5 < b3; b5++) {
                        b9[b4[b5]] = bF.css(b7, b4[b5], false, b6)
                    }
                    return b9
                }
                return b8 !== undefined ? bF.style(b7, b4, b8) : bF.css(b7, b4)
            },
            e, i, arguments.length > 1)
        },
        show: function() {
            return r(this, true)
        },
        hide: function() {
            return r(this)
        },
        toggle: function(e) {
            if (typeof e === "boolean") {
                return e ? this.show() : this.hide()
            }
            return this.each(function() {
                if (Q(this)) {
                    bF(this).show()
                } else {
                    bF(this).hide()
                }
            })
        }
    });
    function H(b3, i, b5, e, b4) {
        return new H.prototype.init(b3, i, b5, e, b4)
    }
    bF.Tween = H;
    H.prototype = {
        constructor: H,
        init: function(b4, i, b6, e, b5, b3) {
            this.elem = b4;
            this.prop = b6;
            this.easing = b5 || "swing";
            this.options = i;
            this.start = this.now = this.cur();
            this.end = e;
            this.unit = b3 || (bF.cssNumber[b6] ? "": "px")
        },
        cur: function() {
            var e = H.propHooks[this.prop];
            return e && e.get ? e.get(this) : H.propHooks._default.get(this)
        },
        run: function(b3) {
            var i, e = H.propHooks[this.prop];
            if (this.options.duration) {
                this.pos = i = bF.easing[this.easing](b3, this.options.duration * b3, 0, 1, this.options.duration)
            } else {
                this.pos = i = b3
            }
            this.now = (this.end - this.start) * i + this.start;
            if (this.options.step) {
                this.options.step.call(this.elem, this.now, this)
            }
            if (e && e.set) {
                e.set(this)
            } else {
                H.propHooks._default.set(this)
            }
            return this
        }
    };
    H.prototype.init.prototype = H.prototype;
    H.propHooks = {
        _default: {
            get: function(i) {
                var e;
                if (i.elem[i.prop] != null && (!i.elem.style || i.elem.style[i.prop] == null)) {
                    return i.elem[i.prop]
                }
                e = bF.css(i.elem, i.prop, "");
                return ! e || e === "auto" ? 0 : e
            },
            set: function(e) {
                if (bF.fx.step[e.prop]) {
                    bF.fx.step[e.prop](e)
                } else {
                    if (e.elem.style && (e.elem.style[bF.cssProps[e.prop]] != null || bF.cssHooks[e.prop])) {
                        bF.style(e.elem, e.prop, e.now + e.unit)
                    } else {
                        e.elem[e.prop] = e.now
                    }
                }
            }
        }
    };
    H.propHooks.scrollTop = H.propHooks.scrollLeft = {
        set: function(e) {
            if (e.elem.nodeType && e.elem.parentNode) {
                e.elem[e.prop] = e.now
            }
        }
    };
    bF.easing = {
        linear: function(e) {
            return e
        },
        swing: fun<a data-type="text" data-hidehit="0" style="width:101px" data-recommtype="103" title="网页游戏大全" data-title="网页游戏大全" data-rpkey target="_blank" class="item_index_1" data-href="https://www.baidu.com/s?wd=%E7%BD%91%E9%A1%B5%E6%B8%B8%E6%88%8F%E5%A4%A7%E5%85%A8&tn=67012150_cpr&fenlei=mv6quAkxTZn0IZRquydsIZb0T1Y4mv7buH6dPHb3njwWPhc30ZwV5fKWUMw85HmLnjDznHRsgvPsT6K1TL0q0ZP1Tjcq0ZNzUjY" anti_hooks_dspui1462952042231="1462952042246">ction(e) {
            return 0.5 - Math.cos(e * Math.PI) / 2
        }
    };
    bF.fx = H.prototype.init;
    bF.fx.step = {};
    var L, ac, bO = /^(?:toggle|show|hide)$/,
    bG = new RegExp("^(?:([+-])=|)(" + aC + ")([a-z%]*)$", "i"),
    bM = /queueHooks$/,
    aE = [h],
    a0 = {
        "*": [function(e, b7) {
            var b9 = this.createTween(e, b7),
            b5 = b9.cur(),
            b4 = bG.exec(b7),
            b8 = b4 && b4[3] || (bF.cssNumber[e] ? "": "px"),
            i = (bF.cssNumber[e] || b8 !== "px" && +b5) && bG.exec(bF.css(b9.elem, e)),
            b3 = 1,
            b6 = 20;
            if (i && i[3] !== b8) {
                b8 = b8 || i[3];
                b4 = b4 || [];
                i = +b5 || 1;
                do {
                    b3 = b3 || ".5";
                    i = i / b3;
                    bF.style(b9.elem, e, i + b8)
                } while ( b3 !== ( b3 = b9 . cur () / b5) && b3 !== 1 && --b6)
            }
            if (b4) {
                i = b9.start = +i || +b5 || 0;
                b9.unit = b8;
                b9.end = b4[1] ? i + (b4[1] + 1) * b4[2] : +b4[2]
            }
            return b9
        }]
    };
    function bk() {
        setTimeout(function() {
            L = undefined
        });
        return (L = bF.now())
    }
    function bE(b4, b6) {
        var b5, e = {
            height: b4
        },
        b3 = 0;
        b6 = b6 ? 1 : 0;
        for (; b3 < 4; b3 += 2 - b6) {
            b5 = bQ[b3];
            e["margin" + b5] = e["padding" + b5] = b4
        }
        if (b6) {
            e.opacity = e.width = b4
        }
        return e
    }
    function bb(b5, b7, b4) {
        var i, b6 = (a0[b7] || []).concat(a0["*"]),
        e = 0,
        b3 = b6.length;
        for (; e < b3; e++) {
            if ((i = b6[e].call(b4, b7, b5))) {
                return i
            }
        }
    }
    function h(b4, b9, e) {
        var b3, cc, b6, cf, cg, cd, b8, cb, b5 = this,
        ca = {},
        i = b4.style,
        b7 = b4.nodeType && Q(b4),
        ce = bF._data(b4, "fxshow");
        if (!e.queue) {
            cg = bF._queueHooks(b4, "fx");
            if (cg.unqueued == null) {
                cg.unqueued = 0;
                cd = cg.empty.fire;
                cg.empty.fire = function() {
                    if (!cg.unqueued) {
                        cd()
                    }
                }
            }
            cg.unqueued++;
            b5.always(function() {
                b5.always(function() {
                    cg.unqueued--;
                    if (!bF.queue(b4, "fx").length) {
                        cg.empty.fire()
                    }
                })
            })
        }
        if (b4.nodeType === 1 && ("height" in b9 || "width" in b9)) {
            e.overflow = [i.overflow, i.overflowX, i.overflowY];
            b8 = bF.css(b4, "display");
            cb = b8 === "none" ? bF._data(b4, "olddisplay") || aY(b4.nodeName) : b8;
            if (cb === "inline" && bF.css(b4, "float") === "none") {
                if (!C.inlineBlockNeedsLayout || aY(b4.nodeName) === "inline") {
                    i.display = "inline-block"
                } else {
                    i.zoom = 1
                }
            }
        }
        if (e.overflow) {
            i.overflow = "hidden";
            if (!C.shrinkWrapBlocks()) {
                b5.always(function() {
                    i.overflow = e.overflow[0];
                    i.overflowX = e.overflow[1];
                    i.overflowY = e.overflow[2]
                })
            }
        }
        for (b3 in b9) {
            cc = b9[b3];
            if (bO.exec(cc)) {
                delete b9[b3];
                b6 = b6 || cc === "toggle";
                if (cc === (b7 ? "hide": "show")) {
                    if (cc === "show" && ce && ce[b3] !== undefined) {
                        b7 = true
                    } else {
                        continue
                    }
                }
                ca[b3] = ce && ce[b3] || bF.style(b4, b3)
            } else {
                b8 = undefined
            }
        }
        if (!bF.isEmptyObject(ca)) {
            if (ce) {
                if ("hidden" in ce) {
                    b7 = ce.hidden
                }
            } else {
                ce = bF._data(b4, "fxshow", {})
            }
            if (b6) {
                ce.hidden = !b7
            }
            if (b7) {
                bF(b4).show()
            } else {
                b5.done(function() {
                    bF(b4).hide()
                })
            }
            b5.done(function() {
                var ch;
                bF._removeData(b4, "fxshow");
                for (ch in ca) {
                    bF.style(b4, ch, ca[ch])
                }
            });
            for (b3 in ca) {
                cf = bb(b7 ? ce[b3] : 0, b3, b5);
                if (! (b3 in ce)) {
                    ce[b3] = cf.start;
                    if (b7) {
                        cf.end = cf.start;
                        cf.start = b3 === "width" || b3 === "height" ? 1 : 0
                    }
                }
            }
        } else {
            if ((b8 === "none" ? aY(b4.nodeName) : b8) === "inline") {
                i.display = b8
            }
        }
    }
    function am(b4, b6) {
        var b3, i, b7, b5, e;
        for (b3 in b4) {
            i = bF.camelCase(b3);
            b7 = b6[i];
            b5 = b4[b3];
            if (bF.isArray(b5)) {
                b7 = b5[1];
                b5 = b4[b3] = b5[0]
            }
            if (b3 !== i) {
                b4[i] = b5;
                delete b4[b3]
            }
            e = bF.cssHooks[i];
            if (e && "expand" in e) {
                b5 = e.expand(b5);
                delete b4[i];
                for (b3 in b5) {
                    if (! (b3 in b4)) {
                        b4[b3] = b5[b3];
                        b6[b3] = b7
                    }
                }
            } else {
                b6[i] = b7
            }
        }
    }
    function f(b3, b7, ca) {
        var cb, e, b6 = 0,
        i = aE.length,
        b9 = bF.Deferred().always(function() {
            delete b5.elem
        }),
        b5 = function() {
            if (e) {
                return false
            }
            var ch = L || bk(),
            ce = Math.max(0, b4.startTime + b4.duration - ch),
            cc = ce / b4.duration || 0,
            cg = 1 - cc,
            cd = 0,
            cf = b4.tweens.length;
            for (; cd < cf; cd++) {
                b4.tweens[cd].run(cg)
            }
            b9.notifyWith(b3, [b4, cg, ce]);
            if (cg < 1 && cf) {
                return ce
            } else {
                b9.resolveWith(b3, [b4]);
                return false
            }
        },
        b4 = b9.promise({
            elem: b3,
            props: bF.extend({},
            b7),
            opts: bF.extend(true, {
                specialEasing: {}
            },
            ca),
            originalProperties: b7,
            originalOptions: ca,
            startTime: L || bk(),
            duration: ca.duration,
            tweens: [],
            createTween: function(ce, cc) {
                var cd = bF.Tween(b3, b4.opts, ce, cc, b4.opts.specialEasing[ce] || b4.opts.easing);
                b4.tweens.push(cd);
                return cd
            },
            stop: function(cd) {
                var cc = 0,
                ce = cd ? b4.tweens.length: 0;
                if (e) {
                    return this
                }
                e = true;
                for (; cc < ce; cc++) {
                    b4.tweens[cc].run(1)
                }
                if (cd) {
                    b9.resolveWith(b3, [b4, cd])
                } else {
                    b9.rejectWith(b3, [b4, cd])
                }
                return this
            }
        }),
        b8 = b4.props;
        am(b8, b4.opts.specialEasing);
        for (; b6 < i; b6++) {
            cb = aE[b6].call(b4, b3, b8, b4.opts);
            if (cb) {
                return cb
            }
        }
        bF.map(b8, bb, b4);
        if (bF.isFunction(b4.opts.start)) {
            b4.opts.start.call(b3, b4)
        }
        bF.fx.timer(bF.extend(b5, {
            elem: b3,
            anim: b4,
            queue: b4.opts.queue
        }));
        return b4.progress(b4.opts.progress).done(b4.opts.done, b4.opts.complete).fail(b4.opts.fail).always(b4.opts.always)
    }
    bF.Animation = bF.extend(f, {
        tweener: function(i, b5) {
            if (bF.isFunction(i)) {
                b5 = i;
                i = ["*"]
            } else {
                i = i.split(" ")
            }
            var b4, e = 0,
            b3 = i.length;
            for (; e < b3; e++) {
                b4 = i[e];
                a0[b4] = a0[b4] || [];
                a0[b4].unshift(b5)
            }
        },
        prefilter: function(i, e) {
            if (e) {
                aE.unshift(i)
            } else {
                aE.push(i)
            }
        }
    });
    bF.speed = function(b3, b4, i) {
        var e = b3 && typeof b3 === "object" ? bF.extend({},
        b3) : {
            complete: i || !i && b4 || bF.isFunction(b3) && b3,
            duration: b3,
            easing: i && b4 || b4 && !bF.isFunction(b4) && b4
        };
        e.duration = bF.fx.off ? 0 : typeof e.duration === "number" ? e.duration: e.duration in bF.fx.speeds ? bF.fx.speeds[e.duration] : bF.fx.speeds._default;
        if (e.queue == null || e.queue === true) {
            e.queue = "fx"
        }
        e.old = e.complete;
        e.complete = function() {
            if (bF.isFunction(e.old)) {
                e.old.call(this)
            }
            if (e.queue) {
                bF.dequeue(this, e.queue)
            }
        };
        return e
    };
    bF.fn.extend({
        fadeTo: function(e, b4, b3, i) {
            return this.filter(Q).css("opacity", 0).show().end().animate({
                opacity: b4
            },
            e, b3, i)
        },
        animate: function(b7, b4, b6, b5) {
            var b3 = bF.isEmptyObject(b7),
            e = bF.speed(b4, b6, b5),
            i = function() {
                var b8 = f(this, bF.extend({},
                b7), e);
                if (b3 || bF._data(this, "finish")) {
                    b8.stop(true)
                }
            };
            i.finish = i;
            return b3 || e.queue === false ? this.each(i) : this.queue(e.queue, i)
        },
        stop: function(b3, i, e) {
            var b4 = function(b5) {
                var b6 = b5.stop;
                delete b5.stop;
                b6(e)
            };
            if (typeof b3 !== "string") {
                e = i;
                i = b3;
                b3 = undefined
            }
            if (i && b3 !== false) {
                this.queue(b3 || "fx", [])
            }
            return this.each(function() {
                var b8 = true,
                b5 = b3 != null && b3 + "queueHooks",
                b7 = bF.timers,
                b6 = bF._data(this);
                if (b5) {
                    if (b6[b5] && b6[b5].stop) {
                        b4(b6[b5])
                    }
                } else {
                    for (b5 in b6) {
                        if (b6[b5] && b6[b5].stop && bM.test(b5)) {
                            b4(b6[b5])
                        }
                    }
                }
                for (b5 = b7.length; b5--;) {
                    if (b7[b5].elem === this && (b3 == null || b7[b5].queue === b3)) {
                        b7[b5].anim.stop(e);
                        b8 = false;
                        b7.splice(b5, 1)
                    }
                }
                if (b8 || !e) {
                    bF.dequeue(this, b3)
                }
            })
        },
        finish: function(e) {
            if (e !== false) {
                e = e || "fx"
            }
            return this.each(function() {
                var b4, b7 = bF._data(this),
                b3 = b7[e + "queue"],
                i = b7[e + "queueHooks"],
                b6 = bF.timers,
                b5 = b3 ? b3.length: 0;
                b7.finish = true;
                bF.queue(this, e, []);
                if (i && i.stop) {
                    i.stop.call(this, true)
                }
                for (b4 = b6.length; b4--;) {
                    if (b6[b4].elem === this && b6[b4].queue === e) {
                        b6[b4].anim.stop(true);
                        b6.splice(b4, 1)
                    }
                }
                for (b4 = 0; b4 < b5; b4++) {
                    if (b3[b4] && b3[b4].finish) {
                        b3[b4].finish.call(this)
                    }
                }
                delete b7.finish
            })
        }
    });
    bF.each(["toggle", "show", "hide"],
    function(b3, e) {
        var b4 = bF.fn[e];
        bF.fn[e] = function(i, b6, b5) {
            return i == null || typeof i === "boolean" ? b4.apply(this, arguments) : this.animate(bE(e, true), i, b6, b5)
        }
    });
    bF.each({
        slideDown: bE("show"),
        slideUp: bE("hide"),
        slideToggle: bE("toggle"),
        fadeIn: {
            opacity: "show"
        },
        fadeOut: {
            opacity: "hide"
        },
        fadeToggle: {
            opacity: "toggle"
        }
    },
    function(e, i) {
        bF.fn[e] = function(b3, b5, b4) {
            return this.animate(i, b3, b5, b4)
        }
    });
    bF.timers = [];
    bF.fx.tick = function() {
        var b4, b3 = bF.timers,
        e = 0;
        L = bF.now();
        for (; e < b3.length; e++) {
            b4 = b3[e];
            if (!b4() && b3[e] === b4) {
                b3.splice(e--, 1)
            }
        }
        if (!b3.length) {
            bF.fx.stop()
        }
        L = undefined
    };
    bF.fx.timer = function(e) {
        bF.timers.push(e);
        if (e()) {
            bF.fx.start()
        } else {
            bF.timers.pop()
        }
    };
    bF.fx.interval = 13;
    bF.fx.start = function() {
        if (!ac) {
            ac = setInterval(bF.fx.tick, bF.fx.interval)
        }
    };
    bF.fx.stop = function() {
        clearInterval(ac);
        ac = null
    };
    bF.fx.speeds = {
        slow: 600,
        fast: 200,
        _default: 400
    };
    bF.fn.delay = function(i, e) {
        i = bF.fx ? bF.fx.speeds[i] || i: i;
        e = e || "fx";
        return this.queue(e,
        function(b4, b3) {
            var b5 = setTimeout(b4, i);
            b3.stop = function() {
                clearTimeout(b5)
            }
        })
    }; (function() {
        var b3, b5, e, i, b4;
        b5 = n.createElement("div");
        b5.setAttribute("className", "t");
        b5.innerHTML = "  <link/><table></table><a href='/a'>a</a><input type='checkbox'/>";
        i = b5.getElementsByTagName("a")[0];
        e = n.createElement("select");
        b4 = e.appendChild(n.createElement("option"));
        b3 = b5.getElementsByTagName("input")[0];
        i.style.cssText = "top:1px";
        C.getSetAttribute = b5.className !== "t";
        C.style = /top/.test(i.getAttribute("style"));
        C.hrefNormalized = i.getAttribute("href") === "/a";
        C.checkOn = !!b3.value;
        C.optSelected = b4.selected;
        C.enctype = !!n.createElement("form").enctype;
        e.disabled = true;
        C.optDisabled = !b4.disabled;
        b3 = n.createElement("input");
        b3.setAttribute("value", "");
        C.input = b3.getAttribute("value") === "";
        b3.value = "t";
        b3.setAttribute("type", "radio");
        C.radioValue = b3.value === "t"
    })();
    var aj = /\r/g;
    bF.fn.extend({
        val: function(b4) {
            var e, i, b5, b3 = this[0];
            if (!arguments.length) {
                if (b3) {
                    e = bF.valHooks[b3.type] || bF.valHooks[b3.nodeName.toLowerCase()];
                    if (e && "get" in e && (i = e.get(b3, "value")) !== undefined) {
                        return i
                    }
                    i = b3.value;
                    return typeof i === "string" ? i.replace(aj, "") : i == null ? "": i
                }
                return
            }
            b5 = bF.isFunction(b4);
            return this.each(function(b6) {
                var b7;
                if (this.nodeType !== 1) {
                    return
                }
                if (b5) {
                    b7 = b4.call(this, b6, bF(this).val())
                } else {
                    b7 = b4
                }
                if (b7 == null) {
                    b7 = ""
                } else {
                    if (typeof b7 === "number") {
                        b7 += ""
                    } else {
                        if (bF.isArray(b7)) {
                            b7 = bF.map(b7,
                            function(b8) {
                                return b8 == null ? "": b8 + ""
                            })
                        }
                    }
                }
                e = bF.valHooks[this.type] || bF.valHooks[this.nodeName.toLowerCase()];
                if (!e || !("set" in e) || e.set(this, b7, "value") === undefined) {
                    this.value = b7
                }
            })
        }
    });
    bF.extend({
        valHooks: {
            option: {
                get: function(e) {
                    var i = bF.find.attr(e, "value");
                    return i != null ? i: bF.trim(bF.text(e))
                }
            },
            select: {
                get: function(e) {
                    var b8, b4, ca = e.options,
                    b6 = e.selectedIndex,
                    b5 = e.type === "select-one" || b6 < 0,
                    b9 = b5 ? null: [],
                    b7 = b5 ? b6 + 1 : ca.length,
                    b3 = b6 < 0 ? b7: b5 ? b6: 0;
                    for (; b3 < b7; b3++) {
                        b4 = ca[b3];
                        if ((b4.selected || b3 === b6) && (C.optDisabled ? !b4.disabled: b4.getAttribute("disabled") === null) && (!b4.parentNode.disabled || !bF.nodeName(b4.parentNode, "optgroup"))) {
                            b8 = bF(b4).val();
                            if (b5) {
                                return b8
                            }
                            b9.push(b8)
                        }
                    }
                    return b9
                },
                set: function(b7, b8) {
                    var b9, b6, b4 = b7.options,
                    e = bF.makeArray(b8),
                    b5 = b4.length;
                    while (b5--) {
                        b6 = b4[b5];
                        if (bF.inArray(bF.valHooks.option.get(b6), e) >= 0) {
                            try {
                                b6.selected = b9 = true
                            } catch(b3) {
                                b6.scrollHeight
                            }
                        } else {
                            b6.selected = false
                        }
                    }
                    if (!b9) {
                        b7.selectedIndex = -1
                    }
                    return b4
                }
            }
        }
    });
    bF.each(["radio", "checkbox"],
    function() {
        bF.valHooks[this] = {
            set: function(e, i) {
                if (bF.isArray(i)) {
                    return (e.checked = bF.inArray(bF(e).val(), i) >= 0)
                }
            }
        };
        if (!C.checkOn) {
            bF.valHooks[this].get = function(e) {
                return e.getAttribute("value") === null ? "on": e.value
            }
        }
    });
    var a8, b0, bL = bF.expr.attrHandle,
    ao = /^(?:checked|selected)$/i,
    bK = C.getSetAttribute,
    bC = C.input;
    bF.fn.extend({
        attr: function(e, i) {
            return az(this, bF.attr, e, i, arguments.length > 1)
        },
        removeAttr: function(e) {
            return this.each(function() {
                bF.removeAttr(this, e)
            })
        }
    });
    bF.extend({
        attr: function(b5, b4, b6) {
            var e, b3, i = b5.nodeType;
            if (!b5 || i === 3 || i === 8 || i === 2) {
                return
            }
            if (typeof b5.getAttribute === aA) {
                return bF.prop(b5, b4, b6)
            }
            if (i !== 1 || !bF.isXMLDoc(b5)) {
                b4 = b4.toLowerCase();
                e = bF.attrHooks[b4] || (bF.expr.match.bool.test(b4) ? b0: a8)
            }
            if (b6 !== undefined) {
                if (b6 === null) {
                    bF.removeAttr(b5, b4)
                } else {
                    if (e && "set" in e && (b3 = e.set(b5, b6, b4)) !== undefined) {
                        return b3
                    } else {
                        b5.setAttribute(b4, b6 + "");
                        return b6
                    }
                }
            } else {
                if (e && "get" in e && (b3 = e.get(b5, b4)) !== null) {
                    return b3
                } else {
                    b3 = bF.find.attr(b5, b4);
                    return b3 == null ? undefined: b3
                }
            }
        },
        removeAttr: function(b4, b6) {
            var e, b5, b3 = 0,
            b7 = b6 && b6.match(aD);
            if (b7 && b4.nodeType === 1) {
                while ((e = b7[b3++])) {
                    b5 = bF.propFix[e] || e;
                    if (bF.expr.match.bool.test(e)) {
                        if (bC && bK || !ao.test(e)) {
                            b4[b5] = false
                        } else {
                            b4[bF.camelCase("default-" + e)] = b4[b5] = false
                        }
                    } else {
                        bF.attr(b4, e, "")
                    }
                    b4.removeAttribute(bK ? e: b5)
                }
            }
        },
        attrHooks: {
            type: {
                set: function(e, i) {
                    if (!C.radioValue && i === "radio" && bF.nodeName(e, "input")) {
                        var b3 = e.value;
                        e.setAttribute("type", i);
                        if (b3) {
                            e.value = b3
                        }
                        return i
                    }
                }
            }
        }
    });
    b0 = {
        set: function(i, b3, e) {
            if (b3 === false) {
                bF.removeAttr(i, e)
            } else {
                if (bC && bK || !ao.test(e)) {
                    i.setAttribute(!bK && bF.propFix[e] || e, e)
                } else {
                    i[bF.camelCase("default-" + e)] = i[e] = true
                }
            }
            return e
        }
    };
    bF.each(bF.expr.match.bool.source.match(/\w+/g),
    function(b4, b3) {
        var e = bL[b3] || bF.find.attr;
        bL[b3] = bC && bK || !ao.test(b3) ?
        function(b6, b5, b8) {
            var i, b7;
            if (!b8) {
                b7 = bL[b5];
                bL[b5] = i;
                i = e(b6, b5, b8) != null ? b5.toLowerCase() : null;
                bL[b5] = b7
            }
            return i
        }: function(b5, i, b6) {
            if (!b6) {
                return b5[bF.camelCase("default-" + i)] ? i.toLowerCase() : null
            }
        }
    });
    if (!bC || !bK) {
        bF.attrHooks.value = {
            set: function(i, b3, e) {
                if (bF.nodeName(i, "input")) {
                    i.defaultValue = b3
                } else {
                    return a8 && a8.set(i, b3, e)
                }
            }
        }
    }
    if (!bK) {
        a8 = {
            set: function(b3, b4, i) {
                var e = b3.getAttributeNode(i);
                if (!e) {
                    b3.setAttributeNode((e = b3.ownerDocument.createAttribute(i)))
                }
                e.value = b4 += "";
                if (i === "value" || b4 === b3.getAttribute(i)) {
                    return b4
                }
            }
        };
        bL.id = bL.name = bL.coords = function(b3, i, b4) {
            var e;
            if (!b4) {
                return (e = b3.getAttributeNode(i)) && e.value !== "" ? e.value: null
            }
        };
        bF.valHooks.button = {
            get: function(b3, i) {
                var e = b3.getAttributeNode(i);
                if (e && e.specified) {
                    return e.value
                }
            },
            set: a8.set
        };
        bF.attrHooks.contenteditable = {
            set: function(i, b3, e) {
                a8.set(i, b3 === "" ? false: b3, e)
            }
        };
        bF.each(["width", "height"],
        function(b3, e) {
            bF.attrHooks[e] = {
                set: function(i, b4) {
                    if (b4 === "") {
                        i.setAttribute(e, "auto");
                        return b4
                    }
                }
            }
        })
    }
    if (!C.style) {
        bF.attrHooks.style = {
            get: function(e) {
                return e.style.cssText || undefined
            },
            set: function(e, i) {
                return (e.style.cssText = i + "")
            }
        }
    }
    var aH = /^(?:input|select|textarea|button|object)$/i,
    E = /^(?:a|area)$/i;
    bF.fn.extend({
        prop: function(e, i) {
            return az(this, bF.prop, e, i, arguments.length > 1)
        },
        removeProp: function(e) {
            e = bF.propFix[e] || e;
            return this.each(function() {
                try {
                    this[e] = undefined;
                    delete this[e]
                } catch(i) {}
            })
        }
    });
    bF.extend({
        propFix: {
            "for": "htmlFor",
            "class": "className"
        },
        prop: function(b6, b4, b7) {
            var b3, e, b5, i = b6.nodeType;
            if (!b6 || i === 3 || i === 8 || i === 2) {
                return
            }
            b5 = i !== 1 || !bF.isXMLDoc(b6);
            if (b5) {
                b4 = bF.propFix[b4] || b4;
                e = bF.propHooks[b4]
            }
            if (b7 !== undefined) {
                return e && "set" in e && (b3 = e.set(b6, b7, b4)) !== undefined ? b3: (b6[b4] = b7)
            } else {
                return e && "get" in e && (b3 = e.get(b6, b4)) !== null ? b3: b6[b4]
            }
        },
        propHooks: {
            tabIndex: {
                get: function(i) {
                    var e = bF.find.attr(i, "tabindex");
                    return e ? parseInt(e, 10) : aH.test(i.nodeName) || E.test(i.nodeName) && i.href ? 0 : -1
                }
            }
        }
    });
    if (!C.hrefNormalized) {
        bF.each(["href", "src"],
        function(b3, e) {
            bF.propHooks[e] = {
                get: function(i) {
                    return i.getAttribute(e, 4)
                }
            }
        })
    }
    if (!C.optSelected) {
        bF.propHooks.selected = {
            get: function(i) {
                var e = i.parentNode;
                if (e) {
                    e.selectedIndex;
                    if (e.parentNode) {
                        e.parentNode.selectedIndex
                    }
                }
                return null
            }
        }
    }
    bF.each(["tabIndex", "readOnly", "maxLength", "cellSpacing", "cellPadding", "rowSpan", "colSpan", "useMap", "frameBorder", "contentEditable"],
    function() {
        bF.propFix[this.toLowerCase()] = this
    });
    if (!C.enctype) {
        bF.propFix.enctype = "encoding"
    }
    var bI = /[\t\r\n\f]/g;
    bF.fn.extend({
        addClass: function(ca) {
            var b4, b3, cb, b8, b5, e, b6 = 0,
            b7 = this.length,
            b9 = typeof ca === "string" && ca;
            if (bF.isFunction(ca)) {
                return this.each(function(i) {
                    bF(this).addClass(ca.call(this, i, this.className))
                })
            }
            if (b9) {
                b4 = (ca || "").match(aD) || [];
                for (; b6 < b7; b6++) {
                    b3 = this[b6];
                    cb = b3.nodeType === 1 && (b3.className ? (" " + b3.className + " ").replace(bI, " ") : " ");
                    if (cb) {
                        b5 = 0;
                        while ((b8 = b4[b5++])) {
                            if (cb.indexOf(" " + b8 + " ") < 0) {
                                cb += b8 + " "
                            }
                        }
                        e = bF.trim(cb);
                        if (b3.className !== e) {
                            b3.className = e
                        }
                    }
                }
            }
            return this
        },
        removeClass: function(ca) {
            var b4, b3, cb, b8, b5, e, b6 = 0,
            b7 = this.length,
            b9 = arguments.length === 0 || typeof ca === "string" && ca;
            if (bF.isFunction(ca)) {
                return this.each(function(i) {
                    bF(this).removeClass(ca.call(this, i, this.className))
                })
            }
            if (b9) {
                b4 = (ca || "").match(aD) || [];
                for (; b6 < b7; b6++) {
                    b3 = this[b6];
                    cb = b3.nodeType === 1 && (b3.className ? (" " + b3.className + " ").replace(bI, " ") : "");
                    if (cb) {
                        b5 = 0;
                        while ((b8 = b4[b5++])) {
                            while (cb.indexOf(" " + b8 + " ") >= 0) {
                                cb = cb.replace(" " + b8 + " ", " ")
                            }
                        }
                        e = ca ? bF.trim(cb) : "";
                        if (b3.className !== e) {
                            b3.className = e
                        }
                    }
                }
            }
            return this
        },
        toggleClass: function(b3, e) {
            var i = typeof b3;
            if (typeof e === "boolean" && i === "string") {
                return e ? this.addClass(b3) : this.removeClass(b3)
            }
            if (bF.isFunction(b3)) {
                return this.each(function(b4) {
                    bF(this).toggleClass(b3.call(this, b4, this.className, e), e)
                })
            }
            return this.each(function() {
                if (i === "string") {
                    var b6, b5 = 0,
                    b4 = bF(this),
                    b7 = b3.match(aD) || [];
                    while ((b6 = b7[b5++])) {
                        if (b4.hasClass(b6)) {
                            b4.removeClass(b6)
                        } else {
                            b4.addClass(b6)
                        }
                    }
                } else {
                    if (i === aA || i === "boolean") {
                        if (this.className) {
                            bF._data(this, "__className__", this.className)
                        }
                        this.className = this.className || b3 === false ? "": bF._data(this, "__className__") || ""
                    }
                }
            })
        },
        hasClass: function(e) {
            var b5 = " " + e + " ",
            b4 = 0,
            b3 = this.length;
            for (; b4 < b3; b4++) {
                if (this[b4].nodeType === 1 && (" " + this[b4].className + " ").replace(bI, " ").indexOf(b5) >= 0) {
                    return true
                }
            }
            return false
        }
    });
    bF.each(("blur focus focusin focusout load resize scroll unload click dblclick mousedown mouseup mousemove mouseover mouseout mouseenter mouseleave change select submit keydown keypress keyup error contextmenu").split(" "),
    function(b3, e) {
        bF.fn[e] = function(b4, i) {
            return arguments.length > 0 ? this.on(e, null, b4, i) : this.trigger(e)
        }
    });
    bF.fn.extend({
        hover: function(e, i) {
            return this.mouseenter(e).mouseleave(i || e)
        },
        bind: function(e, b3, i) {
            return this.on(e, null, b3, i)
        },
        unbind: function(e, i) {
            return this.off(e, null, i)
        },
        delegate: function(e, i, b4, b3) {
            return this.on(i, e, b4, b3)
        },
        undelegate: function(e, i, b3) {
            return arguments.length === 1 ? this.off(e, "**") : this.off(i, e || "**", b3)
        }
    });
    var bm = bF.now();
    var bN = (/\?/);
    var aZ = /(,)|(\[|{)|(}|])|"(?:[^"\\\r\n]|\\["\\\/bfnrt]|\\u[\da-fA-F]{4})*"\s*:?|true|false|null|-?(?!0\d)\d+(?:\.\d+|)(?:[eE][+-]?\d+|)/g;
    bF.parseJSON = function(e) {
        if (a3.JSON && a3.JSON.parse) {
            return a3.JSON.parse(e + "")
        }
        var b4, b3 = null,
        i = bF.trim(e + "");
        return i && !bF.trim(i.replace(aZ,
        function(b7, b5, b6, b8) {
            if (b4 && b5) {
                b3 = 0
            }
            if (b3 === 0) {
                return b7
            }
            b4 = b6 || b5;
            b3 += !b8 - !b6;
            return ""
        })) ? (Function("return " + i))() : bF.error("Invalid JSON: " + e)
    };
    bF.parseXML = function(b4) {
        var i, b3;
        if (!b4 || typeof b4 !== "string") {
            return null
        }
        try {
            if (a3.DOMParser) {
                b3 = new DOMParser();
                i = b3.parseFromString(b4, "text/xml")
            } else {
                i = new ActiveXObject("Microsoft.XMLDOM");
                i.async = "false";
                i.loadXML(b4)
            }
        } catch(b5) {
            i = undefined
        }
        if (!i || !i.documentElement || i.getElementsByTagName("parsererror").length) {
            bF.error("Invalid XML: " + b4)
        }
        return i
    };
    var b1, Y, an = /#.*$/,
    P = /([?&])_=[^&]*/,
    af = /^(.*?):[ \t]*([^\r\n]*)\r?$/mg,
    B = /^(?:about|app|app-storage|.+-extension|file|res|widget):$/,
    q = /^(?:GET|HEAD)$/,
    aI = /^\/\//,
    aT = /^([\w.+-]+:)(?:\/\/(?:[^\/?#]*@|)([^\/?#:]*)(?::(\d+)|)|)/,
    v = {},
    a7 = {},
    aV = "*/".concat("*");
    try {
        Y = location.href
    } catch(bg) {
        Y = n.createElement("a");
        Y.href = "";
        Y = Y.href
    }
    b1 = aT.exec(Y.toLowerCase()) || [];
    function bH(e) {
        return function(b6, b7) {
            if (typeof b6 !== "string") {
                b7 = b6;
                b6 = "*"
            }
            var b3, b4 = 0,
            b5 = b6.toLowerCase().match(aD) || [];
            if (bF.isFunction(b7)) {
                while ((b3 = b5[b4++])) {
                    if (b3.charAt(0) === "+") {
                        b3 = b3.slice(1) || "*"; (e[b3] = e[b3] || []).unshift(b7)
                    } else { (e[b3] = e[b3] || []).push(b7)
                    }
                }
            }
        }
    }
    function p(e, b3, b7, b4) {
        var i = {},
        b5 = (e === a7);
        function b6(b8) {
            var b9;
            i[b8] = true;
            bF.each(e[b8] || [],
            function(cb, ca) {
                var cc = ca(b3, b7, b4);
                if (typeof cc === "string" && !b5 && !i[cc]) {
                    b3.dataTypes.unshift(cc);
                    b6(cc);
                    return false
                } else {
                    if (b5) {
                        return ! (b9 = cc)
                    }
                }
            });
            return b9
        }
        return b6(b3.dataTypes[0]) || !i["*"] && b6("*")
    }
    function s(b3, b4) {
        var e, i, b5 = bF.ajaxSettings.flatOptions || {};
        for (i in b4) {
            if (b4[i] !== undefined) { (b5[i] ? b3: (e || (e = {})))[i] = b4[i]
            }
        }
        if (e) {
            bF.extend(true, b3, e)
        }
        return b3
    }
    function g(b9, b8, b5) {
        var e, b4, b3, b6, i = b9.contents,
        b7 = b9.dataTypes;
        while (b7[0] === "*") {
            b7.shift();
            if (b4 === undefined) {
                b4 = b9.mimeType || b8.getResponseHeader("Content-Type")
            }
        }
        if (b4) {
            for (b6 in i) {
                if (i[b6] && i[b6].test(b4)) {
                    b7.unshift(b6);
                    break
                }
            }
        }
        if (b7[0] in b5) {
            b3 = b7[0]
        } else {
            for (b6 in b5) {
                if (!b7[0] || b9.converters[b6 + " " + b7[0]]) {
                    b3 = b6;
                    break
                }
                if (!e) {
                    e = b6
                }
            }
            b3 = b3 || e
        }
        if (b3) {
            if (b3 !== b7[0]) {
                b7.unshift(b3)
            }
            return b5[b3]
        }
    }
    function ae(cd, b5, ca, b3) {
        var i, b8, cb, b6, b4, cc = {},
        b9 = cd.dataTypes.slice();
        if (b9[1]) {
            for (cb in cd.converters) {
                cc[cb.toLowerCase()] = cd.converters[cb]
            }
        }
        b8 = b9.shift();
        while (b8) {
            if (cd.responseFields[b8]) {
                ca[cd.responseFields[b8]] = b5
            }
            if (!b4 && b3 && cd.dataFilter) {
                b5 = cd.dataFilter(b5, cd.dataType)
            }
            b4 = b8;
            b8 = b9.shift();
            if (b8) {
                if (b8 === "*") {
                    b8 = b4
                } else {
                    if (b4 !== "*" && b4 !== b8) {
                        cb = cc[b4 + " " + b8] || cc["* " + b8];
                        if (!cb) {
                            for (i in cc) {
                                b6 = i.split(" ");
                                if (b6[1] === b8) {
                                    cb = cc[b4 + " " + b6[0]] || cc["* " + b6[0]];
                                    if (cb) {
                                        if (cb === true) {
                                            cb = cc[i]
                                        } else {
                                            if (cc[i] !== true) {
                                                b8 = b6[0];
                                                b9.unshift(b6[1])
                                            }
                                        }
                                        break
                                    }
                                }
                            }
                        }
                        if (cb !== true) {
                            if (cb && cd["throws"]) {
                                b5 = cb(b5)
                            } else {
                                try {
                                    b5 = cb(b5)
                                } catch(b7) {
                                    return {
                                        state: "parsererror",
                                        error: cb ? b7: "No conversion from " + b4 + " to " + b8
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return {
            state: "success",
            data: b5
        }
    }
    bF.extend({
        active: 0,
        lastModified: {},
        etag: {},
        ajaxSettings: {
            url: Y,
            type: "GET",
            isLocal: B.test(b1[1]),
            global: true,
            processData: true,
            async: true,
            contentType: "application/x-www-form-urlencoded; charset=UTF-8",
            accepts: {
                "*": aV,
                text: "text/plain",
                html: "text/html",
                xml: "application/xml, text/xml",
                json: "application/json, text/javascript"
            },
            contents: {
                xml: /xml/,
                html: /html/,
                json: /json/
            },
            responseFields: {
                xml: "responseXML",
                text: "responseText",
                json: "responseJSON"
            },
            converters: {
                "* text": String,
                "text html": true,
                "text json": bF.parseJSON,
                "text xml": bF.parseXML
            },
            flatOptions: {
                url: true,
                context: true
            }
        },
        ajaxSetup: function(i, e) {
            return e ? s(s(i, bF.ajaxSettings), e) : s(bF.ajaxSettings, i)
        },
        ajaxPrefilter: bH(v),
        ajaxTransport: bH(a7),
        ajax: function(b7, b4) {
            if (typeof b7 === "object") {
                b4 = b7;
                b7 = undefined
            }
            b4 = b4 || {};
            var cg, ci, b8, cn, cc, b3, cj, b5, cb = bF.ajaxSetup({},
            b4),
            cp = cb.context || cb,
            ce = cb.context && (cp.nodeType || cp.jquery) ? bF(cp) : bF.event,
            co = bF.Deferred(),
            cl = bF.Callbacks("once memory"),
            b9 = cb.statusCode || {},
            cf = {},
            cm = {},
            b6 = 0,
            ca = "canceled",
            ch = {
                readyState: 0,
                getResponseHeader: function(i) {
                    var e;
                    if (b6 === 2) {
                        if (!b5) {
                            b5 = {};
                            while ((e = af.exec(cn))) {
                                b5[e[1].toLowerCase()] = e[2]
                            }
                        }
                        e = b5[i.toLowerCase()]
                    }
                    return e == null ? null: e
                },
                getAllResponseHeaders: function() {
                    return b6 === 2 ? cn: null
                },
                setRequestHeader: function(i, cq) {
                    var e = i.toLowerCase();
                    if (!b6) {
                        i = cm[e] = cm[e] || i;
                        cf[i] = cq
                    }
                    return this
                },
                overrideMimeType: function(e) {
                    if (!b6) {
                        cb.mimeType = e
                    }
                    return this
                },
                statusCode: function(i) {
                    var e;
                    if (i) {
                        if (b6 < 2) {
                            for (e in i) {
                                b9[e] = [b9[e], i[e]]
                            }
                        } else {
                            ch.always(i[ch.status])
                        }
                    }
                    return this
                },
                abort: function(i) {
                    var e = i || ca;
                    if (cj) {
                        cj.abort(e)
                    }
                    cd(0, e);
                    return this
                }
            };
            co.promise(ch).complete = cl.add;
            ch.success = ch.done;
            ch.error = ch.fail;
            cb.url = ((b7 || cb.url || Y) + "").replace(an, "").replace(aI, b1[1] + "//");
            cb.type = b4.method || b4.type || cb.method || cb.type;
            cb.dataTypes = bF.trim(cb.dataType || "*").toLowerCase().match(aD) || [""];
            if (cb.crossDomain == null) {
                cg = aT.exec(cb.url.toLowerCase());
                cb.crossDomain = !!(cg && (cg[1] !== b1[1] || cg[2] !== b1[2] || (cg[3] || (cg[1] === "http:" ? "80": "443")) !== (b1[3] || (b1[1] === "http:" ? "80": "443"))))
            }
            if (cb.data && cb.processData && typeof cb.data !== "string") {
                cb.data = bF.param(cb.data, cb.traditional)
            }
            p(v, cb, b4, ch);
            if (b6 === 2) {
                return ch
            }
            b3 = cb.global;
            if (b3 && bF.active++===0) {
                bF.event.trigger("ajaxStart")
            }
            cb.type = cb.type.toUpperCase();
            cb.hasContent = !q.test(cb.type);
            b8 = cb.url;
            if (!cb.hasContent) {
                if (cb.data) {
                    b8 = (cb.url += (bN.test(b8) ? "&": "?") + cb.data);
                    delete cb.data
                }
                if (cb.cache === false) {
                    cb.url = P.test(b8) ? b8.replace(P, "$1_=" + bm++) : b8 + (bN.test(b8) ? "&": "?") + "_=" + bm++
                }
            }
            if (cb.ifModified) {
                if (bF.lastModified[b8]) {
                    ch.setRequestHeader("If-Modified-Since", bF.lastModified[b8])
                }
                if (bF.etag[b8]) {
                    ch.setRequestHeader("If-None-Match", bF.etag[b8])
                }
            }
            if (cb.data && cb.hasContent && cb.contentType !== false || b4.contentType) {
                ch.setRequestHeader("Content-Type", cb.contentType)
            }
            ch.setRequestHeader("Accept", cb.dataTypes[0] && cb.accepts[cb.dataTypes[0]] ? cb.accepts[cb.dataTypes[0]] + (cb.dataTypes[0] !== "*" ? ", " + aV + "; q=0.01": "") : cb.accepts["*"]);
            for (ci in cb.headers) {
                ch.setRequestHeader(ci, cb.headers[ci])
            }
            if (cb.beforeSend && (cb.beforeSend.call(cp, ch, cb) === false || b6 === 2)) {
                return ch.abort()
            }
            ca = "abort";
            for (ci in {
                success: 1,
                error: 1,
                complete: 1
            }) {
                ch[ci](cb[ci])
            }
            cj = p(a7, cb, b4, ch);
            if (!cj) {
                cd( - 1, "No Transport")
            } else {
                ch.readyState = 1;
                if (b3) {
                    ce.trigger("ajaxSend", [ch, cb])
                }
                if (cb.async && cb.timeout > 0) {
                    cc = setTimeout(function() {
                        ch.abort("timeout")
                    },
                    cb.timeout)
                }
                try {
                    b6 = 1;
                    cj.send(cf, cd)
                } catch(ck) {
                    if (b6 < 2) {
                        cd( - 1, ck)
                    } else {
                        throw ck
                    }
                }
            }
            function cd(ct, i, cu, cr) {
                var e, cx, cv, cs, cw, cq = i;
                if (b6 === 2) {
                    return
                }
                b6 = 2;
                if (cc) {
                    clearTimeout(cc)
                }
                cj = undefined;
                cn = cr || "";
                ch.readyState = ct > 0 ? 4 : 0;
                e = ct >= 200 && ct < 300 || ct === 304;
                if (cu) {
                    cs = g(cb, ch, cu)
                }
                cs = ae(cb, cs, ch, e);
                if (e) {
                    if (cb.ifModified) {
                        cw = ch.getResponseHeader("Last-Modified");
                        if (cw) {
                            bF.lastModified[b8] = cw
                        }
                        cw = ch.getResponseHeader("etag");
                        if (cw) {
                            bF.etag[b8] = cw
                        }
                    }
                    if (ct === 204 || cb.type === "HEAD") {
                        cq = "nocontent"
                    } else {
                        if (ct === 304) {
                            cq = "notmodified"
                        } else {
                            cq = cs.state;
                            cx = cs.data;
                            cv = cs.error;
                            e = !cv
                        }
                    }
                } else {
                    cv = cq;
                    if (ct || !cq) {
                        cq = "error";
                        if (ct < 0) {
                            ct = 0
                        }
                    }
                }
                ch.status = ct;
                ch.statusText = (i || cq) + "";
                if (e) {
                    co.resolveWith(cp, [cx, cq, ch])
                } else {
                    co.rejectWith(cp, [ch, cq, cv])
                }
                ch.statusCode(b9);
                b9 = undefined;
                if (b3) {
                    ce.trigger(e ? "ajaxSuccess": "ajaxError", [ch, cb, e ? cx: cv])
                }
                cl.fireWith(cp, [ch, cq]);
                if (b3) {
                    ce.trigger("ajaxComplete", [ch, cb]);
                    if (! (--bF.active)) {
                        bF.event.trigger("ajaxStop")
                    }
                }
            }
            return ch
        },
        getJSON: function(e, i, b3) {
            return bF.get(e, i, b3, "json")
        },
        getScript: function(e, i) {
            return bF.get(e, undefined, i, "script")
        }
    });
    bF.each(["get", "post"],
    function(e, b3) {
        bF[b3] = function(i, b5, b6, b4) {
            if (bF.isFunction(b5)) {
                b4 = b4 || b6;
                b6 = b5;
                b5 = undefined
            }
            return bF.ajax({
                url: i,
                type: b3,
                dataType: b4,
                data: b5,
                success: b6
            })
        }
    });
    bF.each(["ajaxStart", "ajaxStop", "ajaxComplete", "ajaxError", "ajaxSuccess", "ajaxSend"],
    function(e, b3) {
        bF.fn[b3] = function(i) {
            return this.on(b3, i)
        }
    });
    bF._evalUrl = function(e) {
        return bF.ajax({
            url: e,
            type: "GET",
            dataType: "script",
            async: false,
            global: false,
            "throws": true
        })
    };
    bF.fn.extend({
        wrapAll: function(e) {
            if (bF.isFunction(e)) {
                return this.each(function(b3) {
                    bF(this).wrapAll(e.call(this, b3))
                })
            }
            if (this[0]) {
                var i = bF(e, this[0].ownerDocument).eq(0).clone(true);
                if (this[0].parentNode) {
                    i.insertBefore(this[0])
                }
                i.map(function() {
                    var b3 = this;
                    while (b3.firstChild && b3.firstChild.nodeType === 1) {
                        b3 = b3.firstChild
                    }
                    return b3
                }).append(this)
            }
            return this
        },
        wrapInner: function(e) {
            if (bF.isFunction(e)) {
                return this.each(function(b3) {
                    bF(this).wrapInner(e.call(this, b3))
                })
            }
            return this.each(function() {
                var i = bF(this),
                b3 = i.contents();
                if (b3.length) {
                    b3.wrapAll(e)
                } else {
                    i.append(e)
                }
            })
        },
        wrap: function(e) {
            var i = bF.isFunction(e);
            return this.each(function(b3) {
                bF(this).wrapAll(i ? e.call(this, b3) : e)
            })
        },
        unwrap: function() {
            return this.parent().each(function() {
                if (!bF.nodeName(this, "body")) {
                    bF(this).replaceWith(this.childNodes)
                }
            }).end()
        }
    });
    bF.expr.filters.hidden = function(e) {
        return e.offsetWidth <= 0 && e.offsetHeight <= 0 || (!C.reliableHiddenOffsets() && ((e.style && e.style.display) || bF.css(e, "display")) === "none")
    };
    bF.expr.filters.visible = function(e) {
        return ! bF.expr.filters.hidden(e)
    };
    var bt = /%20/g,
    aQ = /\[\]$/,
    V = /\r?\n/g,
    b = /^(?:submit|button|image|reset|file)$/i,
    ar = /^(?:input|select|textarea|keygen)/i;
    function j(b3, b5, i, b4) {
        var e;
        if (bF.isArray(b5)) {
            bF.each(b5,
            function(b7, b6) {
                if (i || aQ.test(b3)) {
                    b4(b3, b6)
                } else {
                    j(b3 + "[" + (typeof b6 === "object" ? b7: "") + "]", b6, i, b4)
                }
            })
        } else {
            if (!i && bF.type(b5) === "object") {
                for (e in b5) {
                    j(b3 + "[" + e + "]", b5[e], i, b4)
                }
            } else {
                b4(b3, b5)
            }
        }
    }
    bF.param = function(e, b3) {
        var b4, i = [],
        b5 = function(b6, b7) {
            b7 = bF.isFunction(b7) ? b7() : (b7 == null ? "": b7);
            i[i.length] = encodeURIComponent(b6) + "=" + encodeURIComponent(b7)
        };
        if (b3 === undefined) {
            b3 = bF.ajaxSettings && bF.ajaxSettings.traditional
        }
        if (bF.isArray(e) || (e.jquery && !bF.isPlainObject(e))) {
            bF.each(e,
            function() {
                b5(this.name, this.value)
            })
        } else {
            for (b4 in e) {
                j(b4, e[b4], b3, b5)
            }
        }
        return i.join("&").replace(bt, "+")
    };
    bF.fn.extend({
        serialize: function() {
            return bF.param(this.serializeArray())
        },
        serializeArray: function() {
            return this.map(function() {
                var e = bF.prop(this, "elements");
                return e ? bF.makeArray(e) : this
            }).filter(function() {
                var e = this.type;
                return this.name && !bF(this).is(":disabled") && ar.test(this.nodeName) && !b.test(e) && (this.checked || !aK.test(e))
            }).map(function(e, b3) {
                var b4 = bF(this).val();
                return b4 == null ? null: bF.isArray(b4) ? bF.map(b4,
                function(i) {
                    return {
                        name: b3.name,
                        value: i.replace(V, "\r\n")
                    }
                }) : {
                    name: b3.name,
                    value: b4.replace(V, "\r\n")
                }
            }).get()
        }
    });
    bF.ajaxSettings.xhr = a3.ActiveXObject !== undefined ?
    function() {
        return ! this.isLocal && /^(get|post|head|put|delete|options)$/i.test(this.type) && bB() || be()
    }: bB;
    var ay = 0,
    ah = {},
    aw = bF.ajaxSettings.xhr();
    if (a3.ActiveXObject) {
        bF(a3).on("unload",
        function() {
            for (var e in ah) {
                ah[e](undefined, true)
            }
        })
    }
    C.cors = !!aw && ("withCredentials" in aw);
    aw = C.ajax = !!aw;
    if (aw) {
        bF.ajaxTransport(function(e) {
            if (!e.crossDomain || C.cors) {
                var i;
                return {
                    send: function(b6, b3) {
                        var b4, b5 = e.xhr(),
                        b7 = ++ay;
                        b5.open(e.type, e.url, e.async, e.username, e.password);
                        if (e.xhrFields) {
                            for (b4 in e.xhrFields) {
                                b5[b4] = e.xhrFields[b4]
                            }
                        }
                        if (e.mimeType && b5.overrideMimeType) {
                            b5.overrideMimeType(e.mimeType)
                        }
                        if (!e.crossDomain && !b6["X-Requested-With"]) {
                            b6["X-Requested-With"] = "XMLHttpRequest"
                        }
                        for (b4 in b6) {
                            if (b6[b4] !== undefined) {
                                b5.setRequestHeader(b4, b6[b4] + "")
                            }
                        }
                        b5.send((e.hasContent && e.data) || null);
                        i = function(ca, b9) {
                            var b8, cd, cb;
                            if (i && (b9 || b5.readyState === 4)) {
                                delete ah[b7];
                                i = undefined;
                                b5.onreadystatechange = bF.noop;
                                if (b9) {
                                    if (b5.readyState !== 4) {
                                        b5.abort()
                                    }
                                } else {
                                    cb = {};
                                    b8 = b5.status;
                                    if (typeof b5.responseText === "string") {
                                        cb.text = b5.responseText
                                    }
                                    try {
                                        cd = b5.statusText
                                    } catch(cc) {
                                        cd = ""
                                    }
                                    if (!b8 && e.isLocal && !e.crossDomain) {
                                        b8 = cb.text ? 200 : 404
                                    } else {
                                        if (b8 === 1223) {
                                            b8 = 204
                                        }
                                    }
                                }
                            }
                            if (cb) {
                                b3(b8, cd, cb, b5.getAllResponseHeaders())
                            }
                        };
                        if (!e.async) {
                            i()
                        } else {
                            if (b5.readyState === 4) {
                                setTimeout(i)
                            } else {
                                b5.onreadystatechange = ah[b7] = i
                            }
                        }
                    },
                    abort: function() {
                        if (i) {
                            i(undefined, true)
                        }
                    }
                }
            }
        })
    }
    function bB() {
        try {
            return new a3.XMLHttpRequest()
        } catch(i) {}
    }
    function be() {
        try {
            return new a3.ActiveXObject("Microsoft.XMLHTTP")
        } catch(i) {}
    }
    bF.ajaxSetup({
        accepts: {
            script: "text/javascript, application/javascript, application/ecmascript, application/x-ecmascript"
        },
        contents: {
            script: /(?:java|ecma)script/
        },
        converters: {
            "text script": function(e) {
                bF.globalEval(e);
                return e
            }
        }
    });
    bF.ajaxPrefilter("script",
    function(e) {
        if (e.cache === undefined) {
            e.cache = false
        }
        if (e.crossDomain) {
            e.type = "GET";
            e.global = false
        }
    });
    bF.ajaxTransport("script",
    function(b3) {
        if (b3.crossDomain) {
            var e, i = n.head || bF("head")[0] || n.documentElement;
            return {
                send: function(b4, b5) {
                    e = n.createElement("script");
                    e.async = true;
                    if (b3.scriptCharset) {
                        e.charset = b3.scriptCharset
                    }
                    e.src = b3.url;
                    e.onload = e.onreadystatechange = function(b7, b6) {
                        if (b6 || !e.readyState || /loaded|complete/.test(e.readyState)) {
                            e.onload = e.onreadystatechange = null;
                            if (e.parentNode) {
                                e.parentNode.removeChild(e)
                            }
                            e = null;
                            if (!b6) {
                                b5(200, "success")
                            }
                        }
                    };
                    i.insertBefore(e, i.firstChild)
                },
                abort: function() {
                    if (e) {
                        e.onload(undefined, true)
                    }
                }
            }
        }
    });
    var bp = [],
    a6 = /(=)\?(?=&|$)|\?\?/;
    bF.ajaxSetup({
        jsonp: "callback",
        jsonpCallback: function() {
            var e = bp.pop() || (bF.expando + "_" + (bm++));
            this[e] = true;
            return e
        }
    });
    bF.ajaxPrefilter("json jsonp",
    function(b4, e, b5) {
        var b7, i, b3, b6 = b4.jsonp !== false && (a6.test(b4.url) ? "url": typeof b4.data === "string" && !(b4.contentType || "").indexOf("application/x-www-form-urlencoded") && a6.test(b4.data) && "data");
        if (b6 || b4.dataTypes[0] === "jsonp") {
            b7 = b4.jsonpCallback = bF.isFunction(b4.jsonpCallback) ? b4.jsonpCallback() : b4.jsonpCallback;
            if (b6) {
                b4[b6] = b4[b6].replace(a6, "$1" + b7)
            } else {
                if (b4.jsonp !== false) {
                    b4.url += (bN.test(b4.url) ? "&": "?") + b4.jsonp + "=" + b7
                }
            }
            b4.converters["script json"] = function() {
                if (!b3) {
                    bF.error(b7 + " was not called")
                }
                return b3[0]
            };
            b4.dataTypes[0] = "json";
            i = a3[b7];
            a3[b7] = function() {
                b3 = arguments
            };
            b5.always(function() {
                a3[b7] = i;
                if (b4[b7]) {
                    b4.jsonpCallback = e.jsonpCallback;
                    bp.push(b7)
                }
                if (b3 && bF.isFunction(i)) {
                    i(b3[0])
                }
                b3 = i = undefined
            });
            return "script"
        }
    });
    bF.parseHTML = function(b5, b3, b4) {
        if (!b5 || typeof b5 !== "string") {
            return null
        }
        if (typeof b3 === "boolean") {
            b4 = b3;
            b3 = false
        }
        b3 = b3 || n;
        var i = a.exec(b5),
        e = !b4 && [];
        if (i) {
            return [b3.createElement(i[1])]
        }
        i = bF.buildFragment([b5], b3, e);
        if (e && e.length) {
            bF(e).remove()
        }
        return bF.merge([], i.childNodes)
    };
    var bY = bF.fn.load;
    bF.fn.load = function(b4, b7, b8) {
        if (typeof b4 !== "string" && bY) {
            return bY.apply(this, arguments)
        }
        var e, b3, b5, i = this,
        b6 = b4.indexOf(" ");
        if (b6 >= 0) {
            e = bF.trim(b4.slice(b6, b4.length));
            b4 = b4.slice(0, b6)
        }
        if (bF.isFunction(b7)) {
            b8 = b7;
            b7 = undefined
        } else {
            if (b7 && typeof b7 === "object") {
                b5 = "POST"
            }
        }
        if (i.length > 0) {
            bF.ajax({
                url: b4,
                type: b5,
                dataType: "html",
                data: b7
            }).done(function(b9) {
                b3 = arguments;
                i.html(e ? bF("<div>").append(bF.parseHTML(b9)).find(e) : b9)
            }).complete(b8 &&
            function(ca, b9) {
                i.each(b8, b3 || [ca.responseText, b9, ca])
            })
        }
        return this
    };
    bF.expr.filters.animated = function(e) {
        return bF.grep(bF.timers,
        function(i) {
            return e === i.elem
        }).length
    };
    var bU = a3.document.documentElement;
    function bo(e) {
        return bF.isWindow(e) ? e: e.nodeType === 9 ? e.defaultView || e.parentWindow: false
    }
    bF.offset = {
        setOffset: function(b4, ce, b8) {
            var ca, b7, e, b5, b3, cc, cd, b9 = bF.css(b4, "position"),
            b6 = bF(b4),
            cb = {};
            if (b9 === "static") {
                b4.style.position = "relative"
            }
            b3 = b6.offset();
            e = bF.css(b4, "top");
            cc = bF.css(b4, "left");
            cd = (b9 === "absolute" || b9 === "fixed") && bF.inArray("auto", [e, cc]) > -1;
            if (cd) {
                ca = b6.position();
                b5 = ca.top;
                b7 = ca.left
            } else {
                b5 = parseFloat(e) || 0;
                b7 = parseFloat(cc) || 0
            }
            if (bF.isFunction(ce)) {
                ce = ce.call(b4, b8, b3)
            }
            if (ce.top != null) {
                cb.top = (ce.top - b3.top) + b5
            }
            if (ce.left != null) {
                cb.left = (ce.left - b3.left) + b7
            }
            if ("using" in ce) {
                ce.using.call(b4, cb)
            } else {
                b6.css(cb)
            }
        }
    };
    bF.fn.extend({
        offset: function(i) {
            if (arguments.length) {
                return i === undefined ? this: this.each(function(b7) {
                    bF.offset.setOffset(this, i, b7)
                })
            }
            var e, b6, b4 = {
                top: 0,
                left: 0
            },
            b3 = this[0],
            b5 = b3 && b3.ownerDocument;
            if (!b5) {
                return
            }
            e = b5.documentElement;
            if (!bF.contains(e, b3)) {
                return b4
            }
            if (typeof b3.getBoundingClientRect !== aA) {
                b4 = b3.getBoundingClientRect()
            }
            b6 = bo(b5);
            return {
                top: b4.top + (b6.pageYOffset || e.scrollTop) - (e.clientTop || 0),
                left: b4.left + (b6.pageXOffset || e.scrollLeft) - (e.clientLeft || 0)
            }
        },
        position: function() {
            if (!this[0]) {
                return
            }
            var b3, b4, e = {
                top: 0,
                left: 0
            },
            i = this[0];
            if (bF.css(i, "position") === "fixed") {
                b4 = i.getBoundingClientRect()
            } else {
                b3 = this.offsetParent();
                b4 = this.offset();
                if (!bF.nodeName(b3[0], "html")) {
                    e = b3.offset()
                }
                e.top += bF.css(b3[0], "borderTopWidth", true);
                e.left += bF.css(b3[0], "borderLeftWidth", true)
            }
            return {
                top: b4.top - e.top - bF.css(i, "marginTop", true),
                left: b4.left - e.left - bF.css(i, "marginLeft", true)
            }
        },
        offsetParent: function() {
            return this.map(function() {
                var e = this.offsetParent || bU;
                while (e && (!bF.nodeName(e, "html") && bF.css(e, "position") === "static")) {
                    e = e.offsetParent
                }
                return e || bU
            })
        }
    });
    bF.each({
        scrollLeft: "pageXOffset",
        scrollTop: "pageYOffset"
    },
    function(b3, i) {
        var e = /Y/.test(i);
        bF.fn[b3] = function(b4) {
            return az(this,
            function(b5, b8, b7) {
                var b6 = bo(b5);
                if (b7 === undefined) {
                    return b6 ? (i in b6) ? b6[i] : b6.document.documentElement[b8] : b5[b8]
                }
                if (b6) {
                    b6.scrollTo(!e ? b7: bF(b6).scrollLeft(), e ? b7: bF(b6).scrollTop())
                } else {
                    b5[b8] = b7
                }
            },
            b3, b4, arguments.length, null)
        }
    });
    bF.each(["top", "left"],
    function(e, b3) {
        bF.cssHooks[b3] = a5(C.pixelPosition,
        function(b4, i) {
            if (i) {
                i = F(b4, b3);
                return W.test(i) ? bF(b4).position()[b3] + "px": i
            }
        })
    });
    bF.each({
        Height: "height",
        Width: "width"
    },
    function(e, i) {
        bF.each({
            padding: "inner" + e,
            content: i,
            "": "outer" + e
        },
        function(b3, b4) {
            bF.fn[b4] = function(b8, b7) {
                var b6 = arguments.length && (b3 || typeof b8 !== "boolean"),
                b5 = b3 || (b8 === true || b7 === true ? "margin": "border");
                return az(this,
                function(ca, b9, cb) {
                    var cc;
                    if (bF.isWindow(ca)) {
                        return ca.document.documentElement["client" + e]
                    }
                    if (ca.nodeType === 9) {
                        cc = ca.documentElement;
                        return Math.max(ca.body["scroll" + e], cc["scroll" + e], ca.body["offset" + e], cc["offset" + e], cc["client" + e])
                    }
                    return cb === undefined ? bF.css(ca, b9, b5) : bF.style(ca, b9, cb, b5)
                },
                i, b6 ? b8: undefined, b6, null)
            }
        })
    });
    bF.fn.size = function() {
        return this.length
    };
    bF.fn.andSelf = bF.fn.addBack;
    a3.jQueryDSPUI = a3.$DSPUI = bF;
    return bF
}));