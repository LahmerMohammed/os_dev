webpackHotUpdate("main",{

/***/ "./src/components/SearchBar.tsx":
/*!**************************************!*\
  !*** ./src/components/SearchBar.tsx ***!
  \**************************************/
/*! exports provided: SearchBar */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SearchBar", function() { return SearchBar; });
/* harmony import */ var _home_mohammed_projects_online_shopping_ecommerce_frontend_mui_node_modules_babel_preset_react_app_node_modules_babel_runtime_helpers_esm_objectDestructuringEmpty__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! ./node_modules/babel-preset-react-app/node_modules/@babel/runtime/helpers/esm/objectDestructuringEmpty */ "./node_modules/babel-preset-react-app/node_modules/@babel/runtime/helpers/esm/objectDestructuringEmpty.js");
/* harmony import */ var _material_ui_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @material-ui/core */ "./node_modules/@material-ui/core/index.js");
/* harmony import */ var _material_ui_styles__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @material-ui/styles */ "./node_modules/@material-ui/styles/esm/index.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! react */ "./node_modules/react/index.js");
/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_3___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_3__);
/* harmony import */ var _material_ui_icons_Search__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @material-ui/icons/Search */ "./node_modules/@material-ui/icons/Search.js");
/* harmony import */ var _material_ui_icons_Search__WEBPACK_IMPORTED_MODULE_4___default = /*#__PURE__*/__webpack_require__.n(_material_ui_icons_Search__WEBPACK_IMPORTED_MODULE_4__);

var _jsxFileName = "/home/mohammed/projects/online-shopping/ecommerce-frontend-mui/src/components/SearchBar.tsx";
// prettier-ignore




var SearchField = Object(_material_ui_styles__WEBPACK_IMPORTED_MODULE_2__["styled"])(_material_ui_core__WEBPACK_IMPORTED_MODULE_1__["TextField"])(function () {
  return {
    height: 'inherit',
    '& .css-1o2jng6-MuiOutlinedInput-notchedOutline ': {
      border: 'none !important'
    }
  };
});
function SearchBar(props) {
  var _this = this;

  Object(_home_mohammed_projects_online_shopping_ecommerce_frontend_mui_node_modules_babel_preset_react_app_node_modules_babel_runtime_helpers_esm_objectDestructuringEmpty__WEBPACK_IMPORTED_MODULE_0__["default"])(props);

  var classes = useStyles();
  var categories = ['All Categories', 'Car', 'Clothes', 'Eloctronis', 'Laptop', 'Desktop', 'Camera', 'Toys'];
  return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_3__["createElement"]("div", {
    className: classes.container,
    __self: this,
    __source: {
      fileName: _jsxFileName,
      lineNumber: 29,
      columnNumber: 7
    }
  }, /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_3__["createElement"](_material_ui_icons_Search__WEBPACK_IMPORTED_MODULE_4___default.a, {
    fontSize: "large",
    __self: this,
    __source: {
      fileName: _jsxFileName,
      lineNumber: 30,
      columnNumber: 9
    }
  }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_3__["createElement"](SearchField, {
    fullWidth: true,
    __self: this,
    __source: {
      fileName: _jsxFileName,
      lineNumber: 31,
      columnNumber: 9
    }
  }), /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_3__["createElement"](_material_ui_core__WEBPACK_IMPORTED_MODULE_1__["Select"], {
    defaultValue: categories[0],
    className: classes.select,
    style: {
      backgroundColor: '#f6f9fc',
      minWidth: 150,
      maxWidth: 150,
      textAlign: 'center'
    },
    __self: this,
    __source: {
      fileName: _jsxFileName,
      lineNumber: 32,
      columnNumber: 9
    }
  }, categories.map(function (category) {
    return /*#__PURE__*/react__WEBPACK_IMPORTED_MODULE_3__["createElement"](_material_ui_core__WEBPACK_IMPORTED_MODULE_1__["MenuItem"], {
      value: category,
      __self: _this,
      __source: {
        fileName: _jsxFileName,
        lineNumber: 37,
        columnNumber: 41
      }
    }, category);
  })));
}
var useStyles = Object(_material_ui_styles__WEBPACK_IMPORTED_MODULE_2__["makeStyles"])(function (theme) {
  return Object(_material_ui_styles__WEBPACK_IMPORTED_MODULE_2__["createStyles"])({
    container: {
      display: 'flex',
      width: 'inherit',
      alignItems: 'center',
      border: '1px solid gray',
      borderRadius: '2rem'
    },
    select: {
      '& .css-1o2jng6-MuiOutlinedInput-notchedOutline ': {
        borderRadius: '2rem',
        borderRight: '1px solid transparent',
        border: 'none'
      }
    }
  });
});

/***/ })

})
//# sourceMappingURL=main.86badf618e2559234914.hot-update.js.map