import { useState } from "react";
import { HashRouter, Routes, Route } from "react-router-dom";

import Home from "./pages/Home";

import arrow from './assets/arrow.svg'

function App() {
	return (
		<div className="w-full h-screen relative bg-dark-blue 
                    before:z-10 before:block before:absolute before:blur-xl before:rotate-45 before:-top-[130px] before:left-[140px]
                    before:w-16 before:h-[600px] before:bg-purple">
			<HashRouter>
				<Routes>
					<Route path="/" element={<Home />} />
				</Routes>
			</HashRouter>
      <div className="absolute left-1/2 bottom-10 -translate-x-1/2 flex gap-3">
        <div className="w-3 h-3 rounded-full bg-slate-50 cursor-pointer"></div>
        <div className="w-3 h-3 rounded-full bg-slate-50 cursor-pointer"></div>
        <div className="w-3 h-3 rounded-full bg-slate-50 cursor-pointer"></div>
        <div className="w-3 h-3 rounded-full bg-slate-50 cursor-pointer"></div>
      </div>
      <div className="absolute right-12 bottom-10 flex gap-3 text-white cursor-pointer font-bold">
        <p>Get started</p>
        <img src={arrow} alt="" />
      </div>
		</div>
	);
}

export default App;
